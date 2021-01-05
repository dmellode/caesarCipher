#include "func2.h"

/*Author: Dean D'Mello
 *Function: decode_shift
 *Purpose: Uses encode_shift to determine the decode shift
 *Last Edited: 2020-03-09
 */

int decode_shift (char* line){
    /*Declaration*/
    int shift;

    /*Calculations for decode shift value*/
    shift = (26 - encode_shift(line));

    return (shift);
}