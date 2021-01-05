#include "func2.h"

/*Author: Dean D'Mello
 *Function: file_size
 *Purpose: Calculates size of file in bytes
 *Last Edited: 2020-03-09
 */

int file_size(FILE *fp){
	int sz = 0;
	fseek(fp, 0L, SEEK_END);
	sz = ftell(fp);
	rewind(fp);
	return sz;
}