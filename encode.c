#include "func2.h"

/*Author: Dean D'Mello
 *Function: encode
 *Purpose: Shifts a single character according to given shift value
 *Last Edited: 2020-03-09
 */

char encode (char c, int shift){

    /*Shifting Process*/
        if ((c>='a' && c<='z') || (c>='A' && c<='Z')){ /*Checks if char is a letter*/
            if (shift>=0){
                if ((c>('z'-shift) && c<='z') || (c>('Z'-shift) && c<='Z')){  /*For Non-Negative Shift, checks if final position will wrap around and acts accordingly*/
                    c-=(26-shift);
                }
                else {
                    c+=shift;
                }
            } /*For negative shifts if needed*/
            if (shift<0){
                if ((c>='a' && c<('a'+(shift*(-1)))) || (c>='A' && c<('A'+(shift*(-1))))){ /*For Negative Shift, checks if final position will wrap around and acts accordingly*/
                  c+=(26+shift);
                }
                else {
                    c+=shift;
                }
            }
        }
    return (c);
} 