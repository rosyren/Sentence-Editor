// CS2211a 2020
// Assignment 5
// Rosy Ren
// 251080052
// rren27
// November 30th

/*
 * prompt the user to enter a line to delete
 * free the line
 * relink the list and print out the remaining lines
 */

#include "header.h"

void deleteWord(control *head, int deleteLine){

    printf("\nEnter a line to delete : ");
    scanf("%d", &deleteLine);

    // create previous and current sentence pointers
    sentences *currentSen;
    sentences *prevSen;


    while (deleteLine != '\n' && deleteLine != '\0'){

        // if the number of lines entered is not valid
        if (deleteLine > head -> numSentence){
            printf("enter a valid line number");
        }

        // empty loop to iterate through until we reach the line we wish to delete
        for (currentSen = head -> firstSentence; currentSen != NULL && currentSen -> lineNum != deleteLine; prevSen = currentSen, currentSen = currentSen -> nextSen);

        // if it is the first sentence we wish to delete we point the head towards the next sentence
        if (prevSen == NULL){
            head -> firstSentence = currentSen -> nextSen;
        }

        // we point the node before the deleted sentence to the sentence after the deleted one
        else {
            prevSen -> nextSen = currentSen -> nextSen;
        }

        // we free the nodes and their memory
        free(currentSen -> nextSen);
        free(currentSen -> firstWord);
        free(currentSen);
        printWords(head);

        // loop through until the user enters an empty line
        printf("\nEnter a line to delete : ");
        scanf("%d", &deleteLine);

    }

}