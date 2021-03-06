//user interface
/**********************************************
* Sergio Ruelas
* University of Illinois at Chicago
* CS211 Programming Practicum
* Programing Project 4
* This programming project consists of
*  reading in input and creating a linked list
*  of restaurant orders of which we can
*  analyze the list or modify the list
*  as orders are completed (queued) and
*  deleted or input asks for information such
*  as where in line is order for <name> or
*  how long estimated wait time is for <name>
************************************************
*/

#include "res.h"
int getNextNWSChar ()
{
    int ch;

    ch = getc(stdin);
    if (ch == EOF || ch == '\n')
        return ch;
    while (isspace (ch))
    {
        ch = getc(stdin);
        if (ch == EOF || ch == '\n')
            return ch;
    }
    return ch;
}

/* Clear input until next End of Line Character - \n */
void clearToEoln()
{
    int ch;

    do {
        ch = getc(stdin);
    }
    while ((ch != '\n') && (ch != EOF));
}


/* read in the name until the end of the input */
char *getName()
{
    /* skip over the white space characters */
    int ch;
    ch = getc(stdin);
    while (isspace(ch))
    {
        if ('\n' == ch)  /* error \n ==> no integer given */
            return NULL;
        ch = getc(stdin);
    }

    char *word;
    int size;
    size = 10;
    word = (char *) malloc (sizeof(char) * size);

    // read in character-by-character until the newline is encountered
    int count = 0;

    while (ch != '\n')
    {
        if (count+1 >= size)
        {
            // to grow an array to make it "dynamically sized" using malloc
            char* temp;
            int i;
            size = size * 2;
            temp = (char *) malloc (sizeof(char) * size);

            // copy the characters to the new array
            for (i = 0 ; i < count ; i++)
                temp[i] = word[i];

            free (word);
            word = temp;
        }

        word[count] = ch;
        count++;
        word[count] = '\0';

        // read next character
        ch = getc(stdin);
    }

    if (count > 30)
    {
        count = 30;
        word[count] = '\0';
    }

    /* clear ending white space characters */
    while (isspace (word[count-1]))
    {
        count--;
        word[count] = '\0';
    }

    return word;
}
/* Print out a list of the commands for this program */
void printCommands()
{
    printf ("The commands for this program are:\n\n");
    printf ("q - to quit the program\n");
    printf ("? - to list the accepted commands\n");
    printf ("a <# burgers> <# salads> <name> - to add your order to the order list\n");
    printf ("c <# burgers> <# salads> <name> - to add a call-ahead order to the order list\n");
    printf ("w <name> - to specify a call-ahead group is now waiting in the restaurant\n");
    printf ("r <# burgers> <# salads> - to retrieve the first waiting group whose order matches the items on the counter\n");
    printf ("l <name> - list how many orders are ahead of the named order\n");
    printf ("d - display the order list information\n");
    printf ("t <name> - display an estimated wait time for the given order name\n");

    /* clear input to End of Line */
    clearToEoln();
}

/* read in the next Positive Integer or error:    */
/*    we can count zero as a positive number */
int getPosInt ()
{
    int value = -1;

    /* clear white space characters */
    int ch;
    ch = getc(stdin);
    while (!isdigit(ch))
    {
        if ('\n' == ch)  /* error \n ==> no integer given */
            return -1;
        if (!isspace(ch)) /* error non white space ==> integer not given next */
        {
            clearToEoln();
            return -1;
        }
        ch = getc(stdin);
    }

    value = ch - '0';
    ch = getc(stdin);
    while (isdigit(ch))
    {
        value = value * 10 + ch - '0';
        ch = getc(stdin);
    }

    ungetc (ch, stdin);  /* put the last read character back in input stream */

    /* Integer value less than 0 is an error in this program */
    if (0 > value)
        clearToEoln();

    return value;
}


int main (int argc, char **argv)
{
    //DebugMode = FALSE;
    //int b;
    /*for(b = 0; b < argc; b++){
        if(strcmp(argv[b], "-d") == 0){
            DebugMode = TRUE;
        }
    }//end code to check if the -d flag was given for debugging mode*/
    char *input;
    int ch;
    struct nodeStruct* headptr = NULL;

    printf ("Starting Fast Food Order Management Program\n\n");
    printf ("Enter command: ");

    while ((ch = getNextNWSChar ()) != EOF)
    {
        /* check for the various commands */
        if ('q' == ch){
            printf ("Quitting Program\n");
            return (0);
        }
        else if ('?' == ch){
            printCommands();
        }
        else if('a' == ch) { // <# burgers> <# salads> <name>
            doAdd(&headptr);
            //note this call is from inside the restaurant (inside = TRUE)
        }
        else if('c' == ch){//note this call is from outside the restaurant (inside = FALSE)
            doCallAhead(&headptr);
        }
        else if('w' == ch){ //now waiting inside restaurant
            doWaiting(headptr);
        }
        else if('r' == ch){//send head pointer and check order
            doRetrieve(&headptr); //similar to doAdd but you are removing head ptr
        }
        else if('l' == ch){ //# of orders ahead of named order
            doList(headptr); //# of orders ahead printed in doList function
        }
        else if('d' == ch){ //display order list
            doDisplay(headptr);
        }
        else if('t' == ch){ //estimate wait time for name given
            doEstimateTime(headptr);
        }
        else if('\n' == ch){
            /* nothing entered on input line     *
             * do nothing, but don't give error  */
        }
        else
        {
            printf ("%c - in not a valid command\n", ch);
            printf ("For a list of valid commands, type ?\n");
            clearToEoln();
        }

        printf ("\nEnter command: ");
    }

    printf ("Quiting Program - EOF reached\n");
    return 1;
}
