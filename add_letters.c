#include "func.h"

/*Author: Dean D'Mello
 *Function: add_letters
 *Purpose: Fills an empty int table for letters of the alphabet and their frequency in text
 *Last Edited: 2020-03-09
 */

void add_letters (int* table, char* line){
    /*Declarations*/
    int i, k = 0;
    char j;

    /*Loop through alphabet*/
	for (j='A'; j<='Z'; j++){
		i=0;
		/*Loop to count number of times each letter is found in string*/
		while (line[i]!='\0'){
			if (line[i] == j || line[i] == j+32){
				table[k] += 1;
			}
			i++;		
		}
		k++;
	}
}