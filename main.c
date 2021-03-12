// CS2211a 2020
// Assignment 5
// Rosy Ren
// 251080052
// rren27
// November 30th

/*
 * main function that calls all other functions and runs the main program
 */

#include "header.h"


int main(){

    // declare array string for input, search
    char str[MAXStringSize];
    char searchStr[MAXStringSize];
    // declare int to pass into delete function
    int deleteLine = 0;

    int numSentence = 0;

    // declare a new control structure
    control *head;
    // allocate memory for the structure and initialize it
    head = (control*) calloc (1, sizeof(control));
    head -> firstSentence = NULL;
    head -> numSentence = numSentence;


    // call the other functions
    inputString(head, str);
    printWords(head);
    searchWords(head, searchStr);
    deleteWord(head, deleteLine);

}