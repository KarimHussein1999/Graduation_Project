#include "Bluetooth_HC05.h"
#include "DC_MOTOR.h"
#include "Ultrasonic.h"
#include "IR_Sensor.h"

/*
 *
 * Timer 4 --> PWM Signals (All Channels Are Used)
 * Timer 4 --> Used For Encoder Also
 * Timer 3 --> Ultrasonic
 * Timer 2 --> Ultrasonic
 *
*/

// Free Driving Mode Configuration
#define	FDM_DUTY_CYCLE 2000

// ACC Configurations
#define Near_Safe_Distance	10
#define Medium_Safe_Distance	30
#define Far_Safe_Distance	60

#define DUTYCYCLE_UpperLimit 10000
#define DUTYCYCLE_LowerLimit 100
#define DUTYCYCLESTEP 10

#define SPEEDLIMIT 25
#define MinSPEEDLIMIT 5
#define MaxSPEEDLIMIT 45


typedef enum {Near , Medium , Far}GAP;
typedef enum {DRIVE_STRAIGHT , DRIVE_RIGHT , DRIVE_LEFT , REVERSE , PARKING}DIRECTION;

// Variables For ACC
DIRECTION ACC_STATE = DRIVE_STRAIGHT;
unsigned char data = 0;
unsigned char speed_limit = SPEEDLIMIT;
unsigned char current_speed = 0;
unsigned short distance = 0;
unsigned short dutycycle = 0;
GAP seperation_gap = Medium;

// APS Configurations

#define CAR_WIDTH 30   // Cm
#define MAX_BACK_DISTANCE 30 // Cm
#define MIN_BACK_DISTANCE 3 // Cm
#define APS_DUTY_CYCLE 1000

// Variables For APS
unsigned char  APS_STATE = 0;


// LFS Configurations
#define LFS_DUTY_CYCLE 1000

// Functions Prototypes
void Free_Driving_Mode (void);
void ACC (void);
void APS (void);
void LFS (void);

unsigned char Car_Velocity(void);

// you can feedback system using Bluetooth (send status to Main Controller)

int main(void)
{

	Ultrasonic_Init(FRONT_ULTRASONIC);
	Ultrasonic_Init(BACK_ULTRASONIC);
	Ultrasonic_Init(UPPER_RIGHT_ULTRASONIC);
	Ultrasonic_Init(LOWER_RIGHT_ULTRASONIC);

	IR_Sensor_Init(Left_IR_Sensor);
	IR_Sensor_Init(Right_IR_Sensor);

	Bluetooth_Init();
	Car_Init();

    /* Loop forever */
	for(;;){

		data = Bluetooth_Read();

		// Call System Function Here
		ACC();
	}
}

void Free_Driving_Mode (void)
{
	if(data == 'B')
	{
		Car_Drive(GO,Backward,FDM_DUTY_CYCLE);
	}
	else if(data == 'U')
	{
		Car_Drive(GO,Forward,FDM_DUTY_CYCLE);
	}
	else if(data == 'R')
	{
		Car_Drive(GO,Right,FDM_DUTY_CYCLE);
	}
	else if(data == 'L')
	{
		Car_Drive(GO,Left,FDM_DUTY_CYCLE);
	}
	else if(data == 'S')
	{
		Car_Drive(STOP,Forward,FDM_DUTY_CYCLE);
	}
}

void ACC (void)
{
	// Settings of ACC
	Ultrasonic_Start(FRONT_ULTRASONIC);

	if(data == 'B')
	{
		Car_Drive(GO,Backward,dutycycle);
		ACC_STATE = REVERSE; // ACC Doesn't Support This Mode
	}
	else if(data == 'U')
	{
		Car_Drive(GO,Forward,dutycycle);
		ACC_STATE = DRIVE_STRAIGHT;
	}
	else if(data == 'R')
	{
		Car_Drive(GO,Right,dutycycle);
		ACC_STATE = DRIVE_RIGHT; // ACC Doesn't Support This Mode
	}
	else if(data == 'L')
	{
		Car_Drive(GO,Left,dutycycle);
		ACC_STATE = DRIVE_LEFT; // ACC Doesn't Support This Mode
	}
	else if (data == 'S')
	{
		Car_Drive(STOP,Left,dutycycle);
		ACC_STATE = PARKING; // ACC Doesn't Support This Mode
	}
	else if(data == 'C')
	{
		// Increase Speed Limit
		if (speed_limit<MaxSPEEDLIMIT)
			speed_limit++;
	}
	else if(data == 'D')
	{
		// Decrease Speed Limit
		if(speed_limit>MinSPEEDLIMIT)
			speed_limit--;
	}
	else if(data == 'F')
	{
		// Far Distance
		seperation_gap = Far;
	}
	else if(data == 'M')
	{
		// Medium Distance
		seperation_gap = Medium;
	}
	else if(data == 'N')
	{
		// Near Distance
		seperation_gap = Near;
	}

	// Get Forward Distance
	distance = Ultrasonic_Time(FRONT_ULTRASONIC);

	// Get Car Speed
	current_speed = Car_Velocity();

	// Check On Speed Also !!
	if (distance <= Far_Safe_Distance) // to detect if there any object or not
	{
		// Seperation Gap Control Part
		switch(seperation_gap)
		{
			case Far:
				//  Far_Safe_Distance --> 60 cm
				if (distance < Far_Safe_Distance)
				{
					if(dutycycle > DUTYCYCLE_LowerLimit  - DUTYCYCLESTEP)
					{
						dutycycle -= DUTYCYCLESTEP;
					}
				}
				break;
			case Medium:
				//  Medium_Safe_Distance --> 30 cm
				if(distance > Medium_Safe_Distance)
				{
					if(current_speed < speed_limit)
					{
						if(dutycycle < DUTYCYCLE_UpperLimit - DUTYCYCLESTEP )
						{
							dutycycle += DUTYCYCLESTEP;
						}
					}

					else if (current_speed > speed_limit)
					{
						if(dutycycle > DUTYCYCLE_LowerLimit + DUTYCYCLESTEP)
						{
							dutycycle -= DUTYCYCLESTEP;
						}
					}
				}
				else if (distance < Medium_Safe_Distance)
				{
					if(dutycycle > DUTYCYCLE_LowerLimit +  DUTYCYCLESTEP)
					{
						dutycycle -= DUTYCYCLESTEP;
					}
				}
				break;
			case Near:
				//  Near_Safe_Distance --> 10 cm
				if(distance > Near_Safe_Distance)
				{
					if(current_speed < speed_limit)
					{
						if(dutycycle < DUTYCYCLE_UpperLimit  - DUTYCYCLESTEP)
						{
							dutycycle += DUTYCYCLESTEP;
						}
					}
					else if (current_speed > speed_limit)
					{
						if(dutycycle > DUTYCYCLE_LowerLimit  + DUTYCYCLESTEP)
						{
							dutycycle -= DUTYCYCLESTEP;
						}
					}
				}
				else if (distance < Near_Safe_Distance)
				{
					if(dutycycle > DUTYCYCLE_LowerLimit +  DUTYCYCLESTEP)
					{
						dutycycle -= DUTYCYCLESTEP;
					}
				}
				break;
			default:break;
		}
	}
	else
	{     // Speed Limit Control Part
		   if(speed_limit> current_speed)
		   {
			   if(dutycycle < DUTYCYCLE_UpperLimit -  DUTYCYCLESTEP)
			   {
				   dutycycle += DUTYCYCLESTEP;
			   }
		   }

			else if (speed_limit< current_speed)
			{
				if(dutycycle > DUTYCYCLE_LowerLimit +  DUTYCYCLESTEP)
				{
					dutycycle -= DUTYCYCLESTEP;
				}
			}
	}

	switch(ACC_STATE)
	{
		case REVERSE:
			Car_Drive(GO,Backward,dutycycle);
			break;
		case DRIVE_STRAIGHT:
			Car_Drive(GO,Forward,dutycycle);
			break;
		case DRIVE_LEFT:
			Car_Drive(GO,Left,dutycycle);
			break;
		case DRIVE_RIGHT:
			Car_Drive(GO,Right,dutycycle);
			break;
		case PARKING :
			Car_Drive(STOP,Right,dutycycle);
			break;
		default:break;
	}
}

void APS (void)
{
	unsigned short D1 = 0,D2 = 0;
	switch(APS_STATE)
	{
		case 0:
			Ultrasonic_Start(UPPER_RIGHT_ULTRASONIC);
			D1 = Ultrasonic_Time(UPPER_RIGHT_ULTRASONIC);

			Ultrasonic_Start(LOWER_RIGHT_ULTRASONIC);
			D2 = Ultrasonic_Time(LOWER_RIGHT_ULTRASONIC);

			if(D1 > D2)
			{
				Car_Drive(GO,Right,APS_DUTY_CYCLE);
			}
			else if (D1 < D2)
			{
				Car_Drive(GO,Left,APS_DUTY_CYCLE);
			}
			else
			{
				Car_Drive(STOP,Forward,APS_DUTY_CYCLE);
				if (D1 != 0 && D2 != 0)
					APS_STATE = 1;
			}

			break;
		case 1: // Check The Empty Space

			Car_Drive(GO,Forward,APS_DUTY_CYCLE);

			Ultrasonic_Start(UPPER_RIGHT_ULTRASONIC);
			D1 = Ultrasonic_Time(UPPER_RIGHT_ULTRASONIC);

			if (D1 < CAR_WIDTH)
			{
				APS_STATE = 1;
			}
			else
			{
				APS_STATE = 2;
			}
			break;
		case 2:

			Ultrasonic_Start(UPPER_RIGHT_ULTRASONIC);
			D1 = Ultrasonic_Time(UPPER_RIGHT_ULTRASONIC);
			Ultrasonic_Start(LOWER_RIGHT_ULTRASONIC);
			D2 = Ultrasonic_Time(LOWER_RIGHT_ULTRASONIC);

			// Check CAR_LENGHT
			if(D1 >= CAR_WIDTH)
			{
				if (D2 >= CAR_WIDTH)
				{
					Car_Drive(STOP,Forward,APS_DUTY_CYCLE);
					APS_STATE = 3;
				}
			}
			else
			{
				if (D1 != 0 && D2 != 0)
					APS_STATE = 1;
			}
			break;
		case 3:
			Ultrasonic_Start(BACK_ULTRASONIC);
			D1 = Ultrasonic_Time(BACK_ULTRASONIC);
			Car_Drive(GO,Left,APS_DUTY_CYCLE);
			if (D1 < MAX_BACK_DISTANCE && D1 > MIN_BACK_DISTANCE)
			{
				Car_Drive(STOP,Left,APS_DUTY_CYCLE);
				APS_STATE = 4;
			}
			break;
		case 4:
			Ultrasonic_Start(BACK_ULTRASONIC);
			D1 = Ultrasonic_Time(BACK_ULTRASONIC);
			Car_Drive(GO,Backward,APS_DUTY_CYCLE);

			if (D1 < MIN_BACK_DISTANCE && D1 != 0)
			{
				Car_Drive(STOP,Backward,APS_DUTY_CYCLE);
				APS_STATE = 5;
			}
			break;
		case 5:
			Ultrasonic_Start(UPPER_RIGHT_ULTRASONIC);
			D1 = Ultrasonic_Time(UPPER_RIGHT_ULTRASONIC);
			Ultrasonic_Start(LOWER_RIGHT_ULTRASONIC);
			D2 = Ultrasonic_Time(LOWER_RIGHT_ULTRASONIC);

			if (D1 > D2)
			{
				Car_Drive(GO,Right,APS_DUTY_CYCLE);
			}
			else if(D1 < D2)
			{
				Car_Drive(GO,Left,APS_DUTY_CYCLE);
			}
			else
			{
				Car_Drive(STOP,Right,APS_DUTY_CYCLE);
				if (D1 != 0 && D2 != 0)
					APS_STATE = 6;
			}
			break;
		default:break;
	}
}


void LFS (void)
{
	if(IR_Sensor_Output(Left_IR_Sensor) == LOGIC_ZERO && IR_Sensor_Output(Right_IR_Sensor) == LOGIC_ONE)
	{
		Car_Drive(GO,Right,LFS_DUTY_CYCLE);
	}
	else if (IR_Sensor_Output(Left_IR_Sensor) == LOGIC_ONE && IR_Sensor_Output(Right_IR_Sensor) == LOGIC_ZERO)
	{
		Car_Drive(GO,Left,LFS_DUTY_CYCLE);
	}
	else if (IR_Sensor_Output(Left_IR_Sensor) == LOGIC_ZERO && IR_Sensor_Output(Right_IR_Sensor) == LOGIC_ZERO)
	{
		Car_Drive(STOP,Forward,LFS_DUTY_CYCLE);
	}
	else
	{
		Car_Drive(GO,Forward,LFS_DUTY_CYCLE);
	}
}


// Useful functions
unsigned char Car_Velocity(void)
{
	return (dutycycle*50/10000.0);
	/*
	 * Direct Linear Relation Between Duty Cycle && RPM
	 * V = 2 * PI * N / 60  (N --> RPM)
	 */
}
