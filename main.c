/* 
 * File:   main.c
 * Author: sangkuriang
 * Software penguji FSM debouncer
 * Created on November 14, 2014, 2:17 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "fsm.h"

// /**
 // * menguji FSM dengan input dari text file
 // * @param filename
 // * @return 
 // */
int main(int argc, char** argv) {
    int jumlah_error=0;
    int baris_counter = 0;
    char buffer[1024];
	
    char *filename = "../test2.csv";
    FILE *f;
    f = fopen(filename, "r");
	
	int last_input = 0;
	int input = 0; // parameter untuk FSM
	int state = 0;
	int output = 0;

    for (; !feof(f);) {

        char * hasil;
        baris_counter++;
        hasil = fgets(buffer, 1024, f); // ambil 1 baris dari textfile
        if (hasil != NULL) {
            int kolom1;
            int kolom2;
            //            printf("baris %d %s", baris_counter, buffer);
            // parsing barisnya untuk mendapatkan data per kolom
            sscanf(buffer, "%d,%d", &kolom1, &kolom2);
//            printf("baris %3d %d %d\n", baris_counter, kolom1, kolom2);
            //panggil FSMnya
            {
                input = kolom1;
                fsm(&last_input, input, &state, &output);
                printf("baris %3d %d %d %d last %d state %d", baris_counter, kolom1, kolom2, output, last_input, state);
                if (output != kolom2) {
                    printf(" error");
                    jumlah_error++;
                }
                printf("\n");
            }
        }
    }
    printf("jumlah error:%d\n",jumlah_error);   // seharusnya jumlah error adalah 0
    return (EXIT_SUCCESS);
}

/*
 * 
 */
// int main(int argc, char** argv) {
    // test_fsm("../test2.csv"); // uji dengan file CSV dengan pola input tertentu
    // return (EXIT_SUCCESS);
// }

