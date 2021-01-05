#include "func.h"

/*Author: Dean D'Mello
 *Function: frequency_table
 *Purpose: Program that automates determining of Caesar encoded text and decodes it
 *Usage: ./frequency_table -F filename
 *-F is optional, prints to stdin without filename
 *Last Edited: 2020-03-09
 */

int main (int argc, char* argv[]){
    /*Declaratiopns*/
    FILE *fp;
    int i=0;
    int j=0;
    int k=0;
    int fflag = 1;
	char temp[1024];
    char args[100];
    char filename1[20];
    int lcount = 0;
    int ccount = 0;
    char letter = 'a';
    int* freq = create_freq_table();

    if (argc == 1){
        fflag=1;
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
        i=0;
    }

    /*If Num of Args is Valid*/
    if (argc==1 || argc==3){
    }
    else{
        fprintf (stderr, "%s\n", "ERROR - Invalid number of arguments");
        return (-1);
    }

    /*If -F flag is present*/
    if (fflag == 0){
        if ((fp = fopen (filename1, "r"))!= NULL){
		}
		else {
			/*Error Check if first file doesnt exist*/
			printf ("ERROR- First file doesn't exist\n");
			return (-1);
		}

		while (fgets(temp, 1024, fp)!= NULL){
			lcount += letter_count (temp);
            ccount += strlen(temp)-1;
            add_letters (freq, temp);
		}
        printf ("Total Letters in Text: %d   Total Characters in Text: %d\n", lcount, ccount+1);
		printf ("\n");
        /*Printing table*/
        printf ("Letters\tFrequency\n");
        for (i=0;i<26;i++){
            printf ("%c\t%d\n", letter, freq[i]);
            letter++;
        }
		fclose (fp);
    }

    /*If No Flags Are Present*/
    if (fflag == 1){
        printf ("Enter '.' to end input\n");
		while ((fgets (temp, 1024, stdin)!= NULL) && (temp[0]!= '.' && temp[1]!='\0')){
			if (temp[0] != '.' && temp[1] != '\0'){ /*Stops when a single period is entered*/
                lcount += letter_count (temp);
                ccount += strlen(temp)-1;
                add_letters (freq, temp);
			}
			temp[0] = '\0';
		}

		printf ("\n");
        printf ("Total Letters in Text: %d   Total Characters in Text: %d\n", lcount, ccount);
		printf ("\n");
        /*Printing table*/
        printf ("Letters\tFrequency\n");
        for (i=0;i<26;i++){
            printf ("%c\t%d\n", letter, freq[i]);
            letter++;
        }
    }

    free (freq);
    return (0);
}