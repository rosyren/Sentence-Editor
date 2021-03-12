// CS2211a 2020
// Assignment 5
// Rosy Ren
// 251080052
// rren27
// November 30th

/*
 * prompts users to enter strings and store each sentence as a sentence structure
 * breaks down each sentence and stores each word into a node word structure
 */

#include "header.h"

void inputString(control *head, char *inString) {

    printf("Enter a string: ");
    fgets(inString, MAXStringSize, stdin);

    // initialize the counts
    int lineNum = 1;
    int wordCount = 0;
    int numSentence = 0;

    // loop until the user enters an empty line
    while (inString[0] != '\0' && inString[0] != '\n') {

        // create a new sentence node structure and alloca memory for it
        sentences *newSentence;
        newSentence = (sentences *) malloc (sizeof(sentences));

        // initialize all the variables within the structure
        newSentence -> lineNum = lineNum;
        newSentence -> totalWords = wordCount;
        newSentence -> firstWord = NULL;
        newSentence -> nextSen = NULL;


        // if it's the first sentence node, we point the head to the newly created sentence
        if (head -> firstSentence == NULL){
            head -> firstSentence = newSentence;

        }

        // else we iterate through to the end of the linked list and link the last node to the newly created sentence node
        else  {

            sentences *current;
            current = head -> firstSentence;

            while (current -> nextSen != NULL){
                current = current -> nextSen;
            }
            // point the last sentence
            current -> nextSen = newSentence;

        }

        int position = 0;

        // iterate through the string
        for (int i = 0; i < strlen(inString); i++){

            // if there is a space we continue
            if (inString[i] == ' '){
                continue;
            }

            // if it's the end of the line we stop
            else if (inString[i] == '\n'){
                break;
            }

            // create a new word structure and allocate memory for it
            words *newWord;
            newWord = (words *) malloc(sizeof(words));

            // initialize the new word
            newWord->firstChar = NULL;
            newWord->wordSize = 0;
            newWord->position = position;
            int memoryCount = 0;

            int j = i;

            // while there is no space and not the end of the sentence, we iterate to find out how many letters are within the word
            while (inString[j] != ' ' && inString[j] != '\0' && inString[j] != '\n'){
                memoryCount = memoryCount + 1;
                j++;
            }

            // we then take that number and allocate the right amount of memory
            newWord -> firstChar = (char *) calloc(memoryCount, sizeof(char));

            // initialize variables
            int index = 0;
            int counter = i;
            position ++;

            // take in the word into the first char pointer
            for (i = i; i < counter + memoryCount; i ++) {
                    newWord -> firstChar[index] = inString[i];
                    index ++;
            }

            // assign the word size
            newWord -> wordSize = memoryCount;
            wordCount ++;

            // if this is the first word in the sentence, we point the first word pointer from the sentence to the new word
            if (newSentence -> firstWord  == NULL) {
                newSentence -> firstWord  = newWord;

            }

            // else we will iterate through the linked list of words until we find the end
            else {

                words *current;
                current = newSentence -> firstWord;

                while (current->nextWord != NULL){
                    current = current->nextWord ;
                }

                //link the last word node to the newly created word
                current -> nextWord = newWord;

            }

            // assign position, next word pointer, and total number of words
            newWord -> position = position;
            newWord -> nextWord = NULL;
            newSentence -> totalWords = wordCount;


        }
        numSentence ++;
        lineNum ++;
        head -> numSentence = numSentence;

        // loop through until they enter an empty line
        printf("Enter a string: ");
        fgets(inString, MAXStringSize, stdin);

    }



}