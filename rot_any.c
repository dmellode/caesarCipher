#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Author: Dean D'Mello
 *Program: rot_any
 *Purpose: Decodes a string of text with a given shift value
 *Last Edit: 2020-03-09
 */ 

void rot_any (char * temp, int shift){
    /*Declarations*/
    int i=0;

    /*Shifting Process*/
    while (temp[i]!='\0'){
        if ((temp[i]>='a' && temp[i]<='z') || (temp[i]>='A' && temp[i]<='Z')){ /*Checks if char is a letter*/
            if (shift>=0){
                if ((temp[i]>('z'-shift) && temp[i]<='z') || (temp[i]>('Z'-shift) && temp[i]<='Z')){  /*For Non-Negative Shift, checks if final position will wrap around and acts accordingly*/
                    temp[i]-=(26-shift);
                }
                else {
                    temp[i]+=shift;
                }
            }/*Negative Shifts*/
            if (shift<0){
                if ((temp[i]>='a' && temp[i]<('a'+(shift*(-1)))) || (temp[i]>='A' && temp[i]<('A'+(shift*(-1))))){ /*For Negative Shift, checks if final position will wrap around and acts accordingly*/
                  temp[i]+=(26+shift);
                }
                else {
                    temp[i]+=shift;
                }
            }
        }
        i++;
    }
}