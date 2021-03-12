#// CS2211a 2020
// Assignment 5
// Rosy Ren
// 251080052
// rren27
// November 30th

/*
 * prompt the user to enter a word to search for
 * iterate through and list all the occurrences of the word and none if the word doesn't exist
 */

#include "header.h"

void searchWords(control *head, char *searchStr){


    printf("\nEnter a word to search for: ");
    fgets(searchStr, MAXStringSize, stdin);

    // tracker sentence and word nodes used when iterating
    sentences *currentSen;
    words *currentWord;

    int found = 0;
    while (searchStr[0] != '\n'){

        // iterate through the sentence linked list until the end
        for (currentSen = head -> firstSentence ; currentSen != NULL; currentSen = currentSen -> nextSen){

            // iterate through the words linked list within each sentence until we hit nul
            for (currentWord = currentSen -> firstWord; currentWord != NULL; currentWord = currentWord -> nextWord){

                int k = 0;

                // see if the letters of the current word match up with the word we're searching for
                    while (searchStr[k] == currentWord -> firstChar[k]){
                        //increment tracker int if they're equal
                        k ++;

                    }

                    // if k is the same number as the word size, it means the entire word is the same
                    if (k == currentWord -> wordSize ){
                        printf("%s found in line %d at position %d", currentWord -> firstChar, currentSen -> lineNum, currentWord -> position);
                        found ++;
                    }

            }
        }

        // if not found, we print word not found
        if (found == 0){
            printf("word not found");
        }

        // loop through again
        printf("\nEnter a word to search for: ");
        fgets(searchStr, MAXStringSize, stdin);

    }


}