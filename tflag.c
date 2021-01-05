#include "func2.h"

/*Author: Dean D'Mello
 *Program: tflag
 *Purpose: Prints alphabet frequency table for given text
 *Last Edit: 2020-03-09
 */ 

void tflag (char* line){
    /*Declarations*/
    int lcount = letter_count(line);
    int ccount = strlen(line);
    int* freq_table = create_freq_table ();
    add_letters (freq_table, line); /*Adding the letter frequency to table based on text*/
    int i = 0;
    char letter = 'a';

    /*Headers*/
    printf ("Total Letters in Text: %d   Total Characters in Text: %d\n", lcount, ccount);
	printf ("\n");

    /*Printing table*/
    printf ("Letters\tFrequency\n");
    for (i=0;i<26;i++){
        printf ("%c\t%d\n", letter, freq_table[i]);
        letter++;
    }
    printf ("\n");


    free (freq_table);
}