#include "func.h"

/*Author: Dean D'Mello
 *Function: letter_count
 *Purpose: counts letters in a string
 *Last Edited: 2020-03-09
 */

int letter_count (char* letter){

    /*Declarations*/
    int lcount=0;
    int i=0;

    while (letter[i]!='\0'){
        if ((letter[i]>='A' && letter[i]<='Z') || (letter[i]>='a' && letter[i]<='z')){
            lcount++;
        }
        i++;
    }
    return lcount;
}
