// CS2211a 2020
// Assignment 5
// Rosy Ren
// 251080052
// rren27
// November 30th

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXStringSize 1000

// create the word structure

typedef struct word{
    char *firstChar;
    int wordSize;
    int position;
    struct word* nextWord;
}words;

// create the sentence structure

typedef struct sentence{
    words *firstWord;
    int lineNum;
    int totalWords;
    struct sentence* nextSen;
}sentences;

// create the control structure

typedef struct control{
    sentences *firstSentence;
    int numSentence;
}control;

void inputString(control *, char * ) ;
void printWords(control *);
void searchWords(control *, char *);
void deleteWord(control *, int );