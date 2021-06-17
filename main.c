#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "linkedlist.h"

int main(int argc, char *argv[]) {
	
	FILE* inFile;
	LLNode* ptr;
	LLNode* head = NULL;
	
	if (argc == 2) { // ends program if there is not the correct number of command line arguements
        
    } else {
        printf("ERROR NO ARGS");
        return -1;
    }
	
	inFile = fopen(argv[1], "r");
    
    if (inFile == NULL) { // ends program if file does not open correctly
        printf("ERROR FILE NOT OPEN");
        return -1;
    }
	
	int currID;
	char currName[10];
	double currGPA;
	
	while (fscanf(inFile, "%d,%[^,],%lf", &currID, currName, &currGPA) != EOF) {
	
	ptr = createNode(currID, currName, currGPA);
	head = insertNode(head, ptr);
	
	}
	
	fclose(inFile);
	
	averageGPA(head);
	
	printLL(head);
	
	destroyLL(head);
	
}