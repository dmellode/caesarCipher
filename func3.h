#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define EF {0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749, 0.07707, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150, 0.01974, 0.00074}


struct record {
    char string1[24];
    double dub[24];
    char string2[144];
    int num[12];
};

typedef struct record rec;

int offset (char);
int letter_count (char*);
char encode (char, int);
int* create_freq_table ();
void add_letters (int*, char*);
double chi_sq (int, int*, int);
int encode_shift (char*);
int decode_shift (char*);
void rot_any (char*, int);
int file_size (FILE*);
char* read_char (FILE*, char*);
