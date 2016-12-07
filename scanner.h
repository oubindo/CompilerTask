//
// Created by oubin on 16-11-28.
//

#ifndef COMPILERTASK_SCANNER_H
#define COMPILERTASK_SCANNER_H
#define SIGN_WORD 10
#define PROGRAME_SIZE 300
#define TOKEN_SIZE 50

#include "stdio.h"

typedef struct{
    int wordType;
    char *word;
} Word,*Pt_Word;

extern char const *keywords[];
extern char program[];
extern char reprogram[];
extern char token[];
extern char ch;
extern int key;
extern bool isUseful;
extern int aIndex;

void init();

char getch(char *str);

void getbc(char *str);

void concat();

bool isLetter(char ch);

bool isDigit(char ch);

int reserve();

void retract();

int dtb();

void error();

void empty();

Pt_Word resultWord(int type, char *c);

Pt_Word scanner(char *str);

Pt_Word testDigit(char *str);

#endif //COMPILERTASK_SCANNER_H
