//
// Created by oubin on 16-12-13.
//

#ifndef COMPILERTASK_ANALYSE_H
#define COMPILERTASK_ANALYSE_H
#define STACK_SIZE 20
#define NTERM_SIZE 5
#define TERM_SIZE 10


// 非终结符
extern char const nterms[];
// 终结符
extern char const terms[];
// 预测分析表
extern char const table[NTERM_SIZE][TERM_SIZE];
// 栈
extern char stack[];
extern char sTopElement;
extern int sIndex;
extern int aTemp;

char push(char c);    // 将字符放入栈中
char pop();           // 将栈的顶端字符弹出
int c2i(char c);      // 将非终结字符在表中的index获取来
int ct2i(char c);     // 将终结字符在表中的index获取来
bool isNterms(char c); // 判断是否是非终结符
int yindex(int cindex); // 将词法分析器返回的type换成在表中的index
void initStack();      // 初始化栈，将文法开始符号和$放进去
void getATemp();       // 获取a
void getSTopElement();  // 获取栈顶元素 S
void endInfo(bool suc); // 结束的信息，通过传入是否成功分别做出不同处理
void pushByTable(int nt,int t);  // 通过index完成转化的过程
void analyse();         // 分析方法总入口






#endif //COMPILERTASK_ANALYSE_H
