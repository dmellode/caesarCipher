#include "func3.h"

/*Author: Dean D'Mello
 *Program: copyrecords
 *Purpose: Program that automates determining of Caesar encoded text and copys records of binary files into other files. Decrypts files if necessary.
 *Usage: ./copyrecords -F infile.rec -Outfile.rec -D textfile.txt -r
 *-D and -r are optional
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
    int dflag = 1;
    int rflag = 1;
    char args[100];
    char filename1[20];
    char filename2[20];
    char filename3[20];
    char* line;
    int decode;
    int pos;
    int rec_num;
    rec one;

    if (argc == 1){
        fflag=1;
        oflag=1;
        fprintf (stderr, "%s\n", "ERROR -F or -O flag missing");
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

                while (args[j]!='.'){ /*Loop seeing how far away period in the .rec is*/
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

                while (args[j]!='.'){ /*Loop seeing how far away period in the .rec is*/
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

        /*Checking for -D flag*/
        for (i=0;i<98;i++){
            if (args[i]=='-' && args[i+1]=='D'){
                dflag = 0;
                j=i;
                k=0;

                while (args[j]!='.'){ /*Loop seeing how far away period in the .txt is*/
                    j++;
                    k++;
                }
                strncpy (filename3, &args[i+2], k+2); /*Copy input file name into its own string*/
                filename3[k+2]= '\0'; /*Terminate string with null character*/
            }
        }
        i=0;
        j=0;
        k=0;

        /*Checking for Other Flags Separate (-r)*/
        for (i=0; i<98; i++){
            if (args[i]=='-' && args[i+1]=='r'){
                rflag = 0;
            }
        }
        i=0;

        /*If Num of Args is Valid*/
        if (argc>=1 && argc<=8){
        }
        else{
            fprintf (stderr, "%s\n", "ERROR - Invalid number of arguments");
            return (-1);
        }
    }
    /*If both flags are present*/
    if (fflag==0 && oflag==0){

        if ((fp = fopen(filename1, "rb")) == NULL){
            /*Error Check if first file doesnt exist*/
            fprintf (stderr, "%s\n", "ERROR- First file doesn't exist");
            return (-1);
        }
        if ((fp2 = fopen(filename2, "wb")) == NULL){
            /*Error Check if first file doesnt exist*/
            fprintf (stderr, "%s\n", "ERROR- First file doesn't exist");
            return (-1);
        }
        
        /*If -D flag is present*/
        if (dflag == 0){
            if ((fp3 = fopen (filename3, "r"))!= NULL){
            }
            else {
                /*Error Check if first file doesnt exist*/
                printf ("ERROR- First file doesn't exist\n");
                return (-1);
            }

            /*Reads each character in the first file and places in string*/
            int max_chars = file_size (fp3); /*Calculates max chars using file size function*/
            line = malloc (sizeof(char) * (max_chars+1));
            line = read_char(fp3, line);
            decode = decode_shift (line);
            fclose (fp3);
        }  

        if (rflag == 0){
            fseek (fp, 0, SEEK_END);
            pos = ftell (fp);
            rec_num = pos/sizeof (rec);

            fseek (fp, sizeof (rec) * -1, SEEK_CUR);
            fread (&one, sizeof(rec), 1, fp);
            if (dflag == 0 && decode != 0){
                /*Calls function to read through each character in the line and shifts characters according to shift value*/
                rot_any (one.string1, decode);
                rot_any (one.string2, decode);
            }
            fwrite (&one, sizeof (rec), 1, fp2);

            for (i=0;i<rec_num-1;i++){
                fseek (fp, sizeof (rec)* -2, SEEK_CUR);
                fread (&one, sizeof (rec), 1, fp);
                if (dflag == 0 && decode != 0){
                    /*Calls function to read through each character in the line and shifts characters according to shift value*/
                    rot_any (one.string1, decode);
                    rot_any (one.string2, decode);
                }
                fwrite (&one, sizeof (rec), 1, fp2);
            }
        }


        if (rflag == 1){
            fseek (fp, 0, SEEK_END);
            pos = ftell (fp);
            rec_num = pos/sizeof (rec);

            fseek (fp, 0, SEEK_SET);

            for (i=0;i<rec_num;i++){
                fread (&one, sizeof (rec), 1, fp);
                if (dflag == 0){
                    /*Calls function to read through each character in the line and shifts characters according to shift value*/
                    rot_any (one.string1, decode);
                    rot_any (one.string2, decode);
                }
                fwrite (&one, sizeof (rec), 1, fp2);
            }
        }           
    }

    /*Freeing*/
    free (line);

    fclose (fp);
    fclose (fp2);
    return (0);
}