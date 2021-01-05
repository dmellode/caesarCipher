#include "func2.h"

/*Author: Dean D'Mello
 *Function: offset
 *Purpose: Replaces letters of the alphabet with their coresponding numbers (offests)
 *Last Edited: 2020-03-09
 */

int offset (char let){
    /*Declarations*/
    int i = 0;
    char j;
    
    /*Loops through letters of alphabet and returning corresponding numbers*/
    for (j='A';j<='Z';j++){
        if (j == let || j+32 == let){
            return (i);
        }
        i++;
    }
    return (-1);
}