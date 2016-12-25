//
// Created by oubin on 16-12-25.
// 每个函数都要保证在进入之前已经调用过Scaner并且在调用之后能完全跳过了自己（但是并没有调scaner）
//
#include "recursive.h"
#include "scanner.h"

int sym = -1;

void reerror() {
    printf("error sym %d\n", sym);
}

void scaner() {
    Pt_Word pt_word = scanner(program);
    sym = pt_word->wordType;
    printf("（%d , %s）\n",pt_word->wordType,pt_word->word);
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
void K() {
    if (sym == 28) {
        scaner();
        CN();
        if (sym == 29) scaner();
        else reerror();
    }
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
        AS();
    } else if (sym == 6) {   // 条件语句
        CS();
    } else if (sym == 8) {   // 循环语句
        LS();
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
        scaner();
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
void SA() {
    A();
    while(sym == 22 || sym==23){
        A();
    }
}

// 条件
void C() {
    SA();
    O();
    SA();
}

// 关系运算符
void O() {
    if(sym == 32 ||sym == 33 ||sym == 34 ||sym == 35 ||sym == 36 ||sym == 37) scaner();
    else reerror();
}

// 项
void A() {
    B();
    while(sym == 24 || sym == 25){
        B();
    }
}

// 因子
void B() {
    scaner();
    if(sym == 10 || sym == 20) scaner();
    else if(sym == 26){
        SA();
        scaner();
        if(sym == 27) scaner();
        else reerror();
    }
}

void recursive() {
    scaner();
    P();
    if(sym == 100) printf("success"); else printf("fail");
}