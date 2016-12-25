//
// Created by oubin on 16-12-25.
// 这个头文件和对应cpp文件用于递归分析法
//

#ifndef COMPILERTASK_RECURSIVE_H
#define COMPILERTASK_RECURSIVE_H
#include <stdio.h>

extern int sym;

void scaner();
void reerror();

// 程序
void P();
// 语句块
void K();
// 语句串
void CN();
// 语句
void S();
// 赋值语句
void AS();
// 条件语句
void CS();
// 循环语句
void LS();
// 表达式
void SA();
// 条件
void C();
// 关系运算符
void O();
// 项
void A();
// 因子
void B();

void  recursive();
#endif //COMPILERTASK_RECURSIVE_H
