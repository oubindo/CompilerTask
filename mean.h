//
// Created by oubin on 16-12-24.
//

#ifndef COMPILERTASK_MEAN_H
#define COMPILERTASK_MEAN_H
#define QUAD_SIZE 40

extern int next;
extern Quad quad[];

typedef struct Quad{
    char result[8];
    char ag1[8];
    char op[8];
    char ag2[8];
} *Pt_Quad;


void emit(char *result,char *ag1,char *op,char *ag2);

char* newtemp();




#endif //COMPILERTASK_MEAN_H
