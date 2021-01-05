#include "func2.h"

/*Author: Dean D'Mello
 *Program: decode
 *Purpose: Program that automates determining of Caesar encoded text and decodes it
 *Usage: ./decode -sStxn -F Infile -O Outfile
 *-sStxn and -F and -O are all optional, can read from stdin or print to stdout
 *Last Edit: 2020-03-09
 */ 

int main (int argc, char* argv[]){
    /*Declarations*/
	FILE *fp;
	FILE *fp2;
    FILE *fp3;
    int i=0;
    int j=0;
    int k=0;
    int fflag = 1;
    int oflag = 1;
    int nflag = 1;
    int sflag = 1;
    int Sflag = 1;
    int Tflag = 1;
    int xflag = 1;
	char temp[1024];
    char args[100];
    char filename1[20];
    char filename2[20];
    char tempfile[] = "temp.txt";
    char* line;
    int encode, decode;

    if (argc == 1){
        fflag=1;
        oflag=1;
    }
    else {
        /*Putting First Non-Executable Arguments into string*/
        strcpy (args, argv[1]);

        for (i=2; i<argc; i++){
            strcat (args, argv[i]); /*Putting all Arguments other than excecutable into string*/
        }
        i=0;

        /*Checking for -F flag*/
        for (i=0;i<98;i++){
            if (args[i]=='-' && args[i+1]=='F'){
                fflag = 0;
                j=i;
                k=0;

                while (args[j]!='.'){ /*Loop seeing how far away period in the .txt is*/
                    j++;
                    k++;
                }
                strncpy (filename1, &args[i+2], k+2); /*Copy input file name into its own string*/
                filename1[k+2]= '\0'; /*Terminate string with null character*/
            }
        }
        j=0;
        k=0;

        /*Checking for -O flag*/
        for (i=0;i<98;i++){
            if (args[i]=='-' && args[i+1]=='O'){
                oflag = 0;
                j=i;
                k=0;

                while (args[j]!='.'){ /*Loop seeing how far away period in the .txt is*/
                    j++;
                    k++;
                }
                strncpy (filename2, &args[i+2], k+2); /*Copy input file name into its own string*/
                filename2[k+2]= '\0'; /*Terminate string with null character*/
            }
        }
        i=0;
        j=0;
        k=0;

        /*Checking for Other Flags Separate (-s -t -x -n)*/
        for (i=0; i<98; i++){
            if (args[i]=='-' && args[i+1]=='n'){
                nflag = 0;
            }
            if (args[i]=='-' && args[i+1]=='s'){
                sflag = 0;
            }
            if (args[i]=='-' && args[i+1]=='S'){
                Sflag = 0;
            }
            if (args[i]=='-' && args[i+1]=='t'){
                Tflag = 0;
            }
            if (args[i]=='-' && args[i+1]=='x'){
                xflag = 0;
            }
        }

        /*Checking for Other Flags Together (-stx)*/
        k=1;
        for (i=0; i<98; i++){
            if (args[i]=='-' && args[i+1]!= 'F' && args[i+1]!= 'O'){
                while ((args[i+k]=='n' || args[i+k]=='s' || args[i+k]=='S' || args[i+k]=='t' || args[i+k]=='x') && (args[i+k]!= ' ' && args[i+k]!= '-')){
                    if (args[i+k]=='n'){
                        nflag = 0;
                    }
                    if (args[i+k]=='s'){
                        sflag = 0;
                    }
                    if (args[i+k]=='S'){
                        Sflag = 0;
                    }
                    if (args[i+k]=='t'){
                        Tflag = 0;
                    }
                    if (args[i+k]=='x'){
                        xflag = 0;
                    }
                    k++;
                }

            }
        }
    }

    /*If Num of Args is Valid*/
    if (argc>=1 && argc<=10){
    }
    else{
        fprintf (stderr, "%s\n", "ERROR - Invalid number of arguments");
        return (-1);
    }

    /*If both flags are present*/
    if (fflag==0 && oflag==0){

        if ((fp = fopen (filename1, "r"))!= NULL){
        }
        else {
            /*Error Check if first file doesnt exist*/
            fprintf (stderr, "%s\n", "ERROR- First file doesn't exist");
            return (-1);
        }
        fp2 = fopen (filename2, "w");

        /*Reads each character in the first file and places in string*/
        int max_chars = file_size (fp); /*Calculates max chars using file size function*/
	    line = malloc (sizeof(char) * (max_chars+1));
        line = read_char(fp, line);
        encode = encode_shift (line);
        decode = decode_shift (line);

        if (Sflag == 0){
            printf ("Encode shift = %d\n", encode);
            printf ("\n");
        }

        if (sflag == 0){
            printf ("Decode shift = %d\n", decode);
            printf ("\n");
        }

        if (xflag == 0){
            Xflag (line);
        }

        if (Tflag == 0){
            tflag (line);
        }

        /*Calls function to read through each character in the line and shifts characters according to shift value*/
        rot_any (line, decode);

        /*Puts new string into second file*/
        fputs (line, fp2);
        line[0] = '\0';
        printf ("\n");
    
        fclose (fp);
        fclose (fp2);
    }
    
    /*If only -F Flag is Present*/
    if (fflag == 0 && oflag == 1){
        if ((fp = fopen (filename1, "r"))!= NULL){
		}
		else {
			/*Error Check if first file doesnt exist*/
			printf ("ERROR- First file doesn't exist\n");
			return (-1);
		}

        /*Reads each character in the first file and places in string*/
        int max_chars = file_size (fp); /*Calculates max chars using file size function*/
	    line = malloc (sizeof(char) * (max_chars+1));
        line = read_char(fp, line);
        encode = encode_shift (line);
        decode = decode_shift (line);

        if (Sflag == 0){
            printf ("Encode shift = %d\n", encode);
            printf ("\n");
        }

        if (sflag == 0){
            printf ("Decode shift = %d\n", decode);
            printf ("\n");
        }

        if (xflag == 0){
            Xflag (line);
        }

        if (Tflag == 0){
            tflag (line);
        }

        /*Calls function to read through each character in the line and shifts characters according to shift value*/
        rot_any (line, decode);

        /*Puts new string into stdout*/
        if (nflag == 1){
            fputs (line, stdout);
        }
        line[0] = '\0';
        printf ("\n");
		fclose (fp);
    }


    /*If only -O Flag is Present*/
    if (fflag == 1 && oflag == 0){
        printf ("Hit Ctrl d twice to finish input\n");
        fp2 = fopen (filename2, "w");
        fp3 = fopen (tempfile, "w");
		while ((fgets (temp, 1024, stdin)!= NULL) && (temp[0]!= EOF)){
			if (temp[0] != EOF){ /*Stops when EOF is entered*/
				fputs (temp, fp3); /*Enters all text into temporary text file*/
			}
			temp[0] = '\0';
		}
		fclose (fp3);

        printf ("\n");
        printf ("\n");

		fp3 = fopen (tempfile, "r");

		/*Reads each character in the first file and places in string*/
        int max_chars = file_size (fp); /*Calculates max chars using file size function*/
	    line = malloc (sizeof(char) * (max_chars+1));
        line = read_char(fp3, line);
        encode = encode_shift (line);
        decode = decode_shift (line);

        if (Sflag == 0){
            printf ("Encode shift = %d\n", encode);
            printf ("\n");
        }

        if (sflag == 0){
            printf ("Decode shift = %d\n", decode);
            printf ("\n");
        }

        if (xflag == 0){
            Xflag (line);
        }

        if (Tflag == 0){
            tflag (line);
        }

        /*Calls function to read through each character in the line and shifts characters according to shift value*/
        rot_any (line, decode);

        /*Puts new string into file*/
        fputs (line, fp2);

        line[0] = '\0';
		printf ("\n");
		fclose (fp3);
		remove (tempfile);
        fclose (fp2);
    }
    
    /*If No Flags Are Present*/
    if (fflag == 1 && oflag == 1){
        printf ("Hit Ctrl d twice to finish input\n");
        fp3 = fopen (tempfile, "w");
		while ((fgets (temp, 1024, stdin)!= NULL) && (temp[0]!= EOF)){
			if (temp[0] != EOF){ /*Stops when EOF is entered*/
				fputs (temp, fp3); /*Enters all text into temporary text file*/
			}
			temp[0] = '\0';
		}
		fclose (fp3);

		printf ("\n");
		printf ("\n");
		fp3 = fopen (tempfile, "r");

		/*Reads each character in the first file and places in string*/
        int max_chars = file_size (fp); /*Calculates max chars using file size function*/
	    line = malloc (sizeof(char) * (max_chars+1));
        line = read_char(fp3, line);
        encode = encode_shift (line);
        decode = decode_shift (line);

        if (Sflag == 0){
            printf ("Encode shift = %d\n", encode);
            printf ("\n");
        }

        if (sflag == 0){
            printf ("Decode shift = %d\n", decode);
            printf ("\n");
        }

        if (xflag == 0){
            Xflag (line);
        }

        if (Tflag == 0){
            tflag (line);
        }

        /*Calls function to read through each character in the line and shifts characters according to shift value*/
        rot_any (line, decode);

        /*Puts new string into stdout*/
        if (nflag == 1){
            fputs (line, stdout);
        }
        line[0] = '\0';
		printf ("\n");
		fclose (fp3);
		remove (tempfile);
    }

    /*Freeing*/
    free (line);
    
    return (0);
}