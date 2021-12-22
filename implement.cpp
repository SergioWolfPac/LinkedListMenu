#include "res.h"

void initLink(struct nodeStruct **head){ //initialize and allocate memory for linked list
    struct nodeStruct* temp = (struct nodeStruct*)malloc(sizeof(struct nodeStruct));
    temp->numBurgers = 0;
    temp->numSalads = 0;
    temp->next = NULL; //head was null when sent
    temp->inside = FALSE;
    *head = temp; //head is pointing to temp node
}

void initNode(struct nodeStruct *head){ //might not need this
    struct nodeStruct* temp = (struct nodeStruct*)malloc(sizeof(struct nodeStruct));
    temp->numBurgers = 0;
    temp->numSalads = 0;
    temp->next = NULL; //head was null when sent
    temp->inside = FALSE;
    head->next = temp; //head next is pointing to next
}

void testLink(struct nodeStruct *head){ //test manipulation of data in headptr
    head->numBurgers = 25; //confirmed worked
    strcpy(head->name, "Sergio");
    head->numSalads = 10;
}

boolean doesNameExist(struct nodeStruct *head, char *name, int *i){
    struct nodeStruct* temp = head;
    while(temp != NULL) {
        if (strcmp(temp->name, name) == 0) { //if name in headptr is equal to name
            return TRUE; //switch to now waiting inside the restaurant
        }
        else{
            temp = temp->next;
            *i = *i + 1;
        }
    }
    //if here name is not in list
    return FALSE;
}
