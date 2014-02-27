/* Course: cs300
*  Submitter: Tetteh Hyde
*  Student ID: x464y263
*  
*This program prompt the user for a short less and a long character
*less than 32 characters. It then echo back the input to the screen.
*Next it saves the input to a file named prog1DataFile.
*After each entry the program asks the user whether to continue or exit.
*If the user choose to exit, it then prints to the screen everything that was saved so far. 
*Comment added under the comment section. Both users added the same comments
*/

#include <stdio.h>
#include <ctype.h>


void cleartoendofline( void );

void cleartoendofline( void )
{

	char ch;
	ch = getchar();
	while( ch != '\n' )
		ch = getchar();
}

int main (int argc, const char * argv[]) 

{

//Variable declaration and definition.

	char c; 
        char ch;
	char szIn1[33], szIn2[33], szFilename[32]="prog1DataFile";
	FILE *pFile;
	short i;
	int     exit_flag = 0;
	int     valid_choice;

	while( exit_flag  == 0 ) 

    {
		
//Prompting the user for input

	printf("Enter a short greater than zero and a long character string less than 32 characters:\n\n");
	
        {
//Checking if file prog1DataFile is present. If not it will be created.
//if file exist open it and append user input to it

	pFile = fopen( szFilename, "a+" );

	 if ( pFile != NULL )
	    {
	     for( i=1; i<2; i++)
		{
		 scanf( "%s %[^\n]", szIn1, szIn2);
		 printf( "You entered: %s %s\n\n", szIn1, szIn2);
		 fprintf(pFile, "%s %s\n", szIn1, szIn2);

		 }//for loop

	      rewind( pFile );

	     }//if (pfile != NULL)


	  }

	valid_choice = 0;
	while( valid_choice == 0 ) 

//Prompting the use to see whether she/he want to exit the program after each entry.
	       {
		 printf("Enter Y to continue with the next entry or N to exit (Y/N):");
		    scanf(" %c", &ch );
		    ch = toupper( ch );
		       if((ch == 'Y') || (ch == 'N') )
		         valid_choice = 1;
		        else
		            printf("\007Error: Invalid choice\n");
			    cleartoendofline();
		}//while( valid_choice == 0 )

//In case the user decides to exit the program by chosing "N",
// Everything saved so far in prog1DataFile will be printed 
// to the screen.

		if( ch == 'N' ) 
 			{

                          printf("\nAll of the below entries have been saved to file (prog1DataFile).\n\n");

                 if ((pFile = fopen("prog1DataFile", "r")) == NULL)
                            {
                              perror ("Please make sure that prog1DataFile was created.");
                              return 0;
                            } //if ((pFile = fopen("prog1DataFile", "r")) == NULL)

  
 		  while ((c = fgetc(pFile)) != EOF)
 		            {
                          putchar (c);
 		            } //while ((c = fgetc(pFile)) != EOF)
  
                   fclose(pFile);

                   return 0;
	                 }  //if( ch == 'N' ) 

    } //while( exit_flag  == 0 )
      printf("User 1: exiting main");
} //int main
