#include "func2.h"

/*Author: Dean D'Mello
 *Program: read_char
 *Purpose: Reads in characters from a file into a string
 *Last Edit: 2020-03-09
 */ 

char* read_char (FILE *fp, char* arr_chars){

	/*Declaration*/
	int i=0;

	/*File Reading*/
 
	/*Loop to read chars into array until end of list*/
	i=0;
	while ((arr_chars[i] = fgetc(fp)) !=EOF){
		i++;
	}

	/*Setting final element to NULL*/
	arr_chars[i] = '\0';

	return arr_chars; 
}