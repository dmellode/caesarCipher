#include "func2.h"

/*Author: Dean D'Mello
 *Function: encode_shift
 *Purpose: Finds the lowest chi_value to determine most accurate encode shift
 *Last Edited: 2020-03-09
 */

int encode_shift (char* line){
    /*Declarations*/
    int shift = 0;
    double low_chi = 0;
    double chi = 0;
    int lcount = letter_count(line);
    int* freq_table = create_freq_table ();
    add_letters (freq_table, line); /*Adding the letter frequency to table based on text*/
    int i = 0;

    /*Setting initial Value (Subject to Change)*/
    chi = chi_sq (i, freq_table, lcount);
    shift = i;
    low_chi = chi;

    for (i=0;i<26;i++){
        /*Calculating chi values to compare*/
        chi = chi_sq (i, freq_table, lcount);

        /*Changing chi value to lowest possible and finding best shift*/
        if (chi < low_chi){
            low_chi = chi;
            shift = i;
        }
    }

    /*Smallest chi is too big, text isn't english*/
    if (low_chi>=0.5){
        shift = 0;
    }

    free (freq_table);
    return (shift);
}