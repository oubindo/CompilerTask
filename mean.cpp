//
// Created by oubin on 16-12-24.
//
#include <malloc.h>
#include <cstring>
#include "mean.h"

int next=1;
int k=0;
Pt_Quad quad[QUAD_SIZE];
Pt_Syntax syntax[SYN_SIZE];
int synIndex=0;

void emit(char *result,char *ag1,char *op,char *ag2){
    Pt_Quad pt_quad=(Pt_Quad)malloc(sizeof(Quad));
    pt_quad->result=result;
    pt_quad->ag1=ag1;
    pt_quad->op=op;
    pt_quad->ag2=ag2;
    quad[next++]=pt_quad;
}

void printfQuad(){
    for(int i=1;i<next;i++){
        Pt_Quad pt_quad=quad[i];
        printf("(%d) %s %s %s %s\n",i,quad[i]->result,quad[i]->ag1,quad[i]->op,quad[i]->ag2);
    }
}

void emitIf(char *result,char *arg1, char *op,char *arg2,char *go,int dsc){
    Pt_Quad pt_quad=(Pt_Quad)malloc(sizeof(Quad));
    pt_quad->result=result;
    char *c=(char*)malloc(strlen(arg1)+strlen(op)+strlen(arg2) + 1);
    strcat(c,arg1);
    strcat(c,op);
    strcat(c,arg2);
    pt_quad->ag1=c;
    pt_quad->op=go;
    char *dscstr=(char *)malloc(sizeof(char)*10);;
    sprintf(dscstr,"%d",dsc);
    pt_quad->ag2=dscstr;
    quad[next++]=pt_quad;
}


char* newtemp(){
    char *p;
    char m[8];
    p=(char *)malloc(8);
    k++;
    sprintf(m,"%d",k);
    strcpy(p+1,m);
    p[0]='t';
    return p;
}


void backpatch(int cfalse,int kend){
    char *dscstr=(char *)malloc(sizeof(char)*10);;
    sprintf(dscstr,"%d",kend);
    quad[cfalse]->ag2=dscstr;
}


























