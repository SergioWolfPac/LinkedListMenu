#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 31

typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

//linked list implementation
struct nodeStruct{
    char name[MAX];
    int numBurgers;
    int numSalads;
    boolean inside; //boolean type (see below set equal to False, True, ETC)
    struct nodeStruct* next; //pointer to next node
};

//begin function prototypes
void initLink(struct nodeStruct **head);
void initNode(struct nodeStruct *head);
void testLink(struct nodeStruct *head);
void clearToEoln();
int getNextNWSChar ();
int getPosInt ();
char *getName();
void clearToEoln();
boolean doesNameExist(struct nodeStruct *head, char *name, int *i);
void printCommands();
void doAdd (struct nodeStruct **head);
void doCallAhead (struct nodeStruct **head);
void doWaiting (struct nodeStruct *head);
void doRetrieve (struct nodeStruct** head);
int doList (struct nodeStruct *head);
void doDisplay (struct nodeStruct *head);
void doEstimateTime(struct nodeStruct *head);
