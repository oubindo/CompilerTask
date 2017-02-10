//
// Created by oubin on 16-12-24.
//

#ifndef COMPILERTASK_MEAN_H
#define COMPILERTASK_MEAN_H
#define QUAD_SIZE 50
#define SYN_SIZE 50

typedef struct Quad{
    char *result;
    char *ag1;
    char *op;
    char *ag2;
} *Pt_Quad;

typedef struct Syntax{
    int code;
    int tr;
    int fa;
    int chain;
} *Pt_Syntax;

extern Pt_Quad quad[];
extern Pt_Syntax syntax[];
extern int synIndex;
extern int next;

extern int k;

void emit(char *result,char *ag1,char *op,char *ag2);

void emitIf(char *result,char *arg1, char *op,char *arg2,char *go,int dsc);

void printfQuad();
char* newtemp();

void backpatch(int cfalse,int kend);

#endif //COMPILERTASK_MEAN_H
