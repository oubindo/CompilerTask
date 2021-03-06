//
// Created by oubin on 16-12-25.
// 每个函数都要保证在进入之前已经调用过Scaner并且在调用之后能完全跳过了自己（但是并没有调scaner）
//
#include <malloc.h>
#include <cstring>
#include "recursive.h"
#include "scanner.h"
#include "mean.h"

bool succ=true;
int sym = -1;
Pt_Word pt_word;

void reerror() {
    printf("error sym %d\n", sym);
}

void scaner() {
    Pt_Word  word=scanner(program);
    while(word->wordType ==-1){
        word=scanner(program);
    }
    pt_word=word;
    sym=pt_word->wordType;
    //printf("（%d , %s）\n",pt_word->wordType,pt_word->word);
    return;
}

// 程序
void P() {
    // main()
    if (sym == 1) {
        scaner();
        if (sym == 26) {
            scaner();
            if (sym == 27) {
                scaner();
                K();
            } else reerror();
        } else reerror();
    } else reerror();
}


// 语句块
int K() {
    if (sym == 28) {
        scaner();
        CN();
        if (sym == 29) scaner();
        else reerror();
    }
    int chain=next;
    emitIf("","","","","goto",0);
    // 将整个代码串结束时的next返回
    return chain;
}

// 语句串
void CN() {
    S();
    while (sym == 31) {
        scaner();
        S();
    }
}

// 语句
void S() {
    if (sym == 10) {       // 赋值语句
        //AS();
        char *result=(char *)malloc(sizeof(char));
        strcpy(result,pt_word->word);
        scaner();
        if (sym == 21) {
            char *op=(char *)malloc(sizeof(char));
            strcpy(op,pt_word->word);
            // scaner();       //这里不进行scaner来将完整的送给表达式
            char *temp=SA();
            emit(result,"",op,temp);
            //printf("%d %s %s %s\n",next,result,op,temp);
        }
    } else if (sym == 6) {   // 条件语句 if
        scaner();
        if (sym == 26) {
            int cfalse=C();
            int code=next;
            if (sym == 27) {
                scaner();
                int chain=K();
                backpatch(cfalse-1,code);
                backpatch(cfalse,next);
                backpatch(chain,next);
                if (sym == 7) {
                    scaner();
                    int chain1=K();
                    backpatch(chain,next);
                    backpatch(chain1,next);
                }
            } else reerror();
        } else reerror();
    } else if (sym == 8) {   // 循环语句
        scaner();
        int code=next;
        int chain=K();
        backpatch(chain,next);
        if (sym == 9) {
            scaner();
            if (sym == 26) {
                int cfalse=C();
                backpatch(cfalse-1,code);
                backpatch(cfalse,next);
                if (sym == 27) scaner();
                else reerror();
            } else reerror();
        } else reerror();
    } else if (sym == 29) {
    }
    else reerror();
}

// 赋值语句
void AS() {
    scaner();
    if (sym == 21) {
        // scaner();       //这里不进行scaner来将完整的送给表达式
        SA();
    }
}

// 条件语句
void CS() {
    scaner();
    if (sym == 26) {
        C();
        if (sym == 27) {
            scaner();
            K();
            if (sym == 7) {
                scaner();
                K();
            }
        } else reerror();
    } else reerror();
}

// 循环语句
void LS() {
    scaner();
    K();
    if (sym == 9) {
        scaner();
        if (sym == 26) {
            scaner();
            C();
            if (sym == 27) scaner();
            else reerror();
        } else reerror();
    } else reerror();
}

//   ------------------------------ 注意SA和A和B和C都是没有在进入之前进行scaner的,但是在出来之前都进行了 Scaner  --------------------------------- //

// 表达式
char* SA() {
    char *arg1=A();
    while(sym == 22 || sym==23){
        char *op=pt_word->word;
        char *arg2=A();
        char *result=newtemp();
        emit(result,arg1,op,arg2);
        //printf("%d %s = %s %s %s\n",next,result,arg1,op,arg2);
        arg1=result;
    }
    return arg1;
}

// 条件
int C() {
    char *arg1=SA();
    char *op=O();
    char *arg2=SA();
    emitIf("if",arg1,op,arg2,"goto",0);
    emitIf("","","","","goto",0);
    //printf("if %s %s %s, goto %d\n",arg1,op,arg2,next+2);
    //printf("goto 0");
    return next-1;
}

// 关系运算符
char* O() {
    char *c;
    if(sym == 32 ||sym == 33 ||sym == 34 ||sym == 35 ||sym == 36 ||sym == 37){
        c=(char *)malloc(sizeof(char));
        strcpy(c,pt_word->word);
    }
    else reerror();
    return c;
}

// 项
char* A() {
    char *arg1=B();
    while(sym == 24 || sym == 25){
        char *op=pt_word->word;
        char *arg2=B();
        char *result=newtemp();
        emit(result,arg1,op,arg2);
        //printf("%d %s = %s %s %s\n",next,result,arg1,op,arg2);
        arg1=result;
    }
    return arg1;
}

// 因子
char* B() {
    scaner();
    if(!(pt_word->wordType==10 || pt_word->wordType== 20)){
        printf("error %s\n",pt_word->word);
        succ=false;
    }
    char *c=(char *)malloc(sizeof(char));
    strcpy(c,pt_word->word);
    //c=pt_word->word;
    //char *c=pt_word->word;
    if(sym == 10 || sym == 20) {
        scaner();
    }else if(sym == 26){                                                  // 这里暂时不做处理
        SA();
        scaner();
        if(sym == 27) scaner();
        else reerror();
    }
    return c;
}

void recursive() {
    scaner();
    P();
    printfQuad();
    if(sym == 100 && succ) printf("success"); else printf("fail");
}
