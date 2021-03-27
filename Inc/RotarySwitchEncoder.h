/*
 * RotarySwitchEncoder.h
 *
 *  Created on: Dec 29, 2020
 *      Author: Karim Hussein
 */

#ifndef ROTARYSWITCHENCODER_H_
#define ROTARYSWITCHENCODER_H_

// Gear Ration 1:500

void RotarySwitchEncoder_Init (void);
unsigned short RotarySwitchEncoder_GetRPM(void);
unsigned short Car_velocity(void);


#endif /* ROTARYSWITCHENCODER_H_ */

// for 1 rotation we have 500 pulse --> assume we have 1 cycle per sec --> we have 500 pulse per sec --> Period = 1 / 500sec
// we can use input capture unit to measure the period
