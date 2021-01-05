#include "func2.h"

/*Author: Dean D'Mello
 *Function: chi_sq
 *Purpose: Formula to calculate chi squared values of different shifts
 *Last Edited: 2020-03-09
 */

double chi_sq (int shift, int* text_freq, int n){
    /*Declaration*/
    char c;
    double ef[26] = EF; /*Making local english frequency table*/
    double chi_value = 0;

    /*Summation and actual formula*/
    for (c='A';c<='Z';c++){
        chi_value += (((n * ef[offset(c)]) - (text_freq[offset(encode(c, shift))])) * ((n * ef[offset(c)]) - (text_freq[offset(encode(c, shift))])))/(n * n * ef[offset(c)]);
    }
   

    return (chi_value);
}