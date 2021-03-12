// CS2211a 2020
// Assignment 5
// Rosy Ren
// 251080052
// rren27
// November 30th

/*
 * this will print out the sentences stored in the order they were entered
 */

#include "header.h"

void printWords(control *head){

    // initialize the tracker nodes for sentence and words
    sentences *currentSen = head -> firstSentence;
    words *currentWord;

    printf("\nthis is all the sentences inputted by the user: \n");

    // iterate through the sentences and iterate through the words
    while (currentSen != NULL) {

        currentWord = currentSen->firstWord;

        while (currentWord != NULL) {

            printf("%s ", currentWord->firstChar);
            currentWord = currentWord->nextWord;

        }

        printf("\n");
        currentSen = currentSen->nextSen;

    }

}