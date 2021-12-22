#include "res.h"

void doAdd (struct nodeStruct **head){ //head is from main to be changed
    //catching nodeStruct * as head but may be sent as new temp
    /* get number of burgers ordered from input */
    int NumBurgers = getPosInt();
    if (NumBurgers < 0)
    {
        printf ("Error: Add command requires an integer value of at least 0\n");
        printf ("Add command is of form: a <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }

    /* get number of salads ordered from input */
    int NumSalads = getPosInt();
    if (NumSalads < 0)
    {
        printf ("Error: Add command requires an integer value of at least 0\n");
        printf ("Add command is of form: a <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }

    /* get group name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: Add command requires a name to be given\n");
        printf ("Add command is of form: a <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }
    /*
    if(DebugMode == TRUE) {
        printf ("Adding In-restaurant order for \"%s\": %d burgers and %d salads\n", name,NumBurgers ,NumSalads);
    }*/
    // add code to perform this operation here
    struct nodeStruct** headRef = head;

    while(*headRef){
        headRef = &(*headRef)->next;
    }
    struct nodeStruct* newNode = (struct nodeStruct*)malloc(sizeof(struct nodeStruct));
    newNode->next = *headRef;
    newNode->numBurgers = NumBurgers;
    newNode->numSalads = NumSalads;
    strcpy(newNode->name, name);
    newNode->inside = TRUE;
    *headRef = newNode;
}

void doCallAhead (struct nodeStruct **head){
    /* get number of burgers ordered from input */
    int NumBurgers = getPosInt();
    if (NumBurgers < 0)
    {
        printf ("Error: Call-ahead command requires an integer value of at least 0\n");
        printf ("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }

    /* get number of salads ordered from input */
    int NumSalads = getPosInt();
    if (NumSalads < 0)
    {
        printf ("Error: Call-ahead command requires an integer value of at least 0\n");
        printf ("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }

    /* get group name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: Call-ahead command requires a name to be given\n");
        printf ("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }
    /*
    if(DebugMode == TRUE) {
        printf ("Adding Call-ahead order for \"%s\": %d burgers and %d salads\n", name,NumBurgers ,NumSalads);
    }*/

    struct nodeStruct** headRef = head;

    while(*headRef){
        headRef = &(*headRef)->next;
    }
    struct nodeStruct* newNode = (struct nodeStruct*)malloc(sizeof(struct nodeStruct));
    newNode->next = *headRef;
    newNode->numBurgers = NumBurgers;
    newNode->numSalads = NumSalads;
    strcpy(newNode->name, name);
    newNode->inside = FALSE;
    *headRef = newNode;
}

void doWaiting (struct nodeStruct *head)
{
    /* get order name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: Waiting command requires a name to be given\n");
        printf ("Waiting command is of form: w <name>\n");
        printf ("  where: <name> is the name of the group that is now waiting\n");
        return;
    }
    /*
    if(DebugMode == TRUE) {
        printf ("Call-ahead order \"%s\" is now waiting in the restaurant\n", name);
    }*/
//search for name
    struct nodeStruct* temp = head;
    while(temp != NULL) {
        if (strcmp(temp->name, name) == 0) { //if name in headptr is equal to name
            temp->inside = TRUE; //switch to now waiting inside the restaurant
            break;
        }
        else{
            temp = temp->next;
        }
    }
}

void doRetrieve (struct nodeStruct** head){
    /* get info of prepared food ready on the counter from input */
    int PreparedBurgers = getPosInt();
    if (PreparedBurgers < 0)
    {
        printf ("Error: Retrieve command requires an integer value of at least 0\n");
        printf ("Retrieve command is of form: r <# burgers> <# salads>\n");
        printf ("  where: <# burgers> is the number of burgers waiting on the counter for pick up\n");
        printf ("         <# saladss> is the number of salads waiting on the counter for pick up\n");
        return;
    }

    int PreparedSalads = getPosInt();
    if (PreparedSalads < 0)
    {
        printf ("Error: Retrieve command requires an integer value of at least 0\n");
        printf ("Retrieve command is of form: r <# burgers> <# salads>\n");
        printf ("  where: <# burgers> is the number of burgers waiting on the counter for pick up\n");
        printf ("         <# saladss> is the number of salads waiting on the counter for pick up\n");
        return;
    }

    clearToEoln();
    printf ("Retrieve (and remove) the first group that can pick up the order of %d burgers and %d salads\n", PreparedBurgers ,PreparedSalads);

    struct nodeStruct** headRef = head;

    while(*headRef){
        headRef = &(*headRef)->next;
    }
    struct nodeStruct* temp = *head;
    struct nodeStruct* previous = *head;
    while(temp != NULL){
        printf("\nafter temp != null check");
        printf("\ntemp->numBurgers is %d and temp->numSalads is %d", temp->numBurgers, temp->numSalads);
        printf("\nPreparedBurgers is %d and PreparedSalads is %d", PreparedBurgers, PreparedSalads);

        if((temp->numBurgers >= PreparedBurgers) && (temp->numSalads >= PreparedSalads)){

            printf("\nInside of numburgers check");
            //remove from list and set next to next
            if(temp == *head){
                //previous is still pointing to head meaning order of head is being deleted
                printf("Removing head %s", temp->name);
                *head = temp->next;
                free(temp);
                return;
            }
            previous->next = temp->next;
            free(temp);
            return;
        }
        else{
            previous = temp;
            temp = temp->next;
        }
    }
    //if here error was made and order cannot be picked up or list is empty
    printf("\nError in doRetrieve");
}

int doList (struct nodeStruct *head){
    /* get order name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: List command requires a name to be given\n");
        printf ("List command is of form: l <name>\n");
        printf ("  where: <name> is the name of the order to inquire about\n");
        return -1;
    }

    printf ("Order for \"%s\" is behind the following orders\n", name);

    // add code to perform this operation here
    int i = 0; //counter variable
    int j = 1; //another counter
    struct nodeStruct* temp = head;
    if(doesNameExist(temp, name, &i)){
        if(j == (i + 1)){ //note + 1 is the difference between counting from 1,2,3 and accessing 0,1,2,3
            printf("You are the first on the list!");
            return 0;
        }
        for(j = 1; j <= i; j++){
            printf("\nOrder number %d for %s: %d Burgers and %d Salads", j, temp->name, temp->numBurgers, temp->numSalads);
            temp = temp->next;
        }
    }
    else {
        printf("\nName not in list");
        return 0; //name not in list
    }
    //search through linked list for the name (same code as doWaiting search for name)
}

void doDisplay (struct nodeStruct *head){
    clearToEoln();
    printf ("Display information about all orders\n");

    // add code to perform this operation here
    //using headptr iterate through list and print values
    if(head == NULL){
        printf("\nList is empty!");
        return;
    }
    while(head != NULL){
        printf("\n%s: # of burgers %d # of salads %d and is", head->name,
               head->numBurgers, head->numSalads);
        printf(head->inside ? " in restaurant" : " not in restaurant");
        head = head->next;
    }
}

void doEstimateTime(struct nodeStruct *head){
    /* get order name from input */

    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: List command requires a name to be given\n");
        printf ("List command is of form: t <name>\n");
        printf ("  where: <name> is the name of the order to inquire about\n");
        return;
    }
    // add code to perform this operation here
    //preparing burgers will take 10 minutes and preparing salads takes 5 minutes
    int i = 0; //not used for counting, sending as a requirement for doesNameExist()
    int burgerTime = 0;
    int saladTime = 0;
    int totalTime = 0;
    struct nodeStruct* temp = head;
    if(doesNameExist(temp, name, &i)){
        while(temp->next != NULL){
            burgerTime = burgerTime + temp->numBurgers;
            saladTime = saladTime + temp->numSalads;
            temp = temp->next;
        }
        burgerTime = burgerTime * 10;
        saladTime = saladTime * 5;
        totalTime = burgerTime + saladTime;
        printf("\nEstimated wait time for %s is %d minutes!", name, totalTime);
    }
    else{
        //name does not exist
        printf("\nError in doEstimateTime, Name does not exist");
    }
}
