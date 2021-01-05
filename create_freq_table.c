#include "func.h"

/*Author: Dean D'Mello
 *Function: create_freq_table
 *Purpose: Creates an empty int table for letters of the alphabet and their frequency in text
 *Last Edited: 2020-03-09
 */

int* create_freq_table (){
    /*Declaration*/
    int *table;
    int i;

    /*Malloc*/
    table = malloc (sizeof(int)* 26);

    for (i=0; i<26; i++){
        table[i] = 0;
    }

    return table;
}