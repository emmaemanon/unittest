/* 
 * File:   fsm.h
 * Author: admin
 *
 * Created on November 16, 2014, 5:24 PM
 */

#ifndef FSM_H
#define	FSM_H

#define START 		0
#define STAGE_00	1
#define STAGE_01	2
#define STAGE_02	3
#define STAGE_03	4
#define STAGE_04	5
#define STAGE_05	6
#define STAGE_06	7
#define STAGE_07	8
#define STAGE_08	9

void fsm(int *last_input, int input, int *state, int *output);

#endif	/* FSM_H */

