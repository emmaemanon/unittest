#include <stdio.h>
#include <stdlib.h>
#include "fsm.h"

// file ini berisi FSM yang akan diuji

/**
 * FSM under test
 * @param input
 * @param state
 * @param output
 */
void fsm(int *last_input, int input, int *state, int *output) {
	// int last_input[5] = {0};
	// int last_count = 0;
	// int count = 0;
	// int last_input = 0;
    // algoritma FSM di sini
	switch(*state){
		case START:
			*last_input = input;
			*output = input;
			*state = STAGE_00;
		break;
		case STAGE_00:
			*output = *last_input;
			*state = STAGE_01;
		break;
		case STAGE_01:
			*output = *last_input;
			*state = STAGE_02;
		break;
		case STAGE_02:
			*output = *last_input;
			*state = STAGE_03;
		break;
		case STAGE_03:
			*output = *last_input;
			*state = STAGE_04;
		break;
		case STAGE_04:
			*output = *last_input;
			*state = STAGE_05;
		break;
		case STAGE_05:
			*output = *last_input;
			*state = STAGE_06;
		break;
		case STAGE_06:
			*output = *last_input;
			*state = STAGE_07;
		break;
		case STAGE_07:
			*output = *last_input;
			*state = STAGE_08;
		break;
		case STAGE_08:
			if (input != *last_input) {
				*last_input = input;
				*output = input;
				*state = STAGE_00;
			}
			else { *output = *last_input; *state = STAGE_08; }
		break;
		// case SCAN_STAGE_00:
			// output = input;
			// *state = SCAN_STAGE_00;
		// break;
		default: break;
	}
    // *output = input;
}
