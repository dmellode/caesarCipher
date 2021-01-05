#include "func2.h"

/*Author: Dean D'Mello
 *Program: Xflag
 *Purpose: Prints table for chi squared values of each shift
 *Last Edit: 2020-03-09
 */ 

void Xflag (char* line){
    /*Declarations*/
    int lcount = letter_count(line);
    int* freq_table = create_freq_table ();
    add_letters (freq_table, line); /*Adding the letter frequency to table based on text*/
    int i = 0;
    double chi = 0;

    /*Printing table*/
    printf ("Shift\tChi Squared Value\n");
    for (i=0;i<26;i++){
        chi = chi_sq (i, freq_table, lcount);
        printf ("%d\t%f\n", i, chi);
    }
    printf ("\n");

    free (freq_table);
}