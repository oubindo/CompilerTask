//
// Created by oubin on 16-12-13.
//
#include "analyse.h"
#include "scanner.h"

// 在放入stack栈的时候都加上一百处理
char const nterms[]={'E','A','T','B','F','$'};
char const terms[]={'+','-','*','/','(',')','i','#','n'};
char stack[STACK_SIZE];
char sTopElement;
int aTemp;

int sIndex=0;

char const table[NTERM_SIZE][TERM_SIZE]={
        {0,0,0,0,1,0,1,0,1,0},
        {1,1,0,0,0,1,0,1,0,1},
        {0,0,0,0,1,0,1,0,1,0},
        {1,1,1,1,0,1,0,1,0,1},
        {0,0,0,0,1,0,1,0,1,0}
};

// 栈顶元素返回数值
int c2i(char c){
    switch(c){
        case 'E':
            return 0;
        case 'A':
            return 1;
        case 'T':
            return 2;
        case 'B':
            return 3;
        case 'F':
            return 4;
        case '$':
            return 9;
        default:
            return -1;
    }
}

int ct2i(char c){
    switch(c){
        case '+':
            return 0;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
        case '(':
            return 4;
        case ')':
            return 5;
        case 'i':
            return 6;
        case '#':
            return 7;
        case 'n':
            return 8;
        case '$':
            return 9;
        default:
            return -1;
    }
}


bool isNterms(char c){
    for(int i=0;i< sizeof(nterms);i++){
        if(c==nterms[i]) return true;
    }
    return false;
}



char push(char c){
    stack[sIndex++]=c;
    return c;
}

char pop(){
    sIndex--;
    char c = stack[sIndex];
    stack[sIndex]='\0';
    return c;
}


// 返回词法对应的语法序,如果无效就返回-1
int yindex(int cindex){
    switch (cindex){
        case 22:
            return 0;
        case 23:
            return 1;
        case 24:
            return 2;
        case 25:
            return 3;
        case 26:
            return 4;
        case 27:
            return 5;
        // id
        case 10:
            return 6;
        // 符号
        case 0:
            return 7;
        // 数字
        case 20:
            return 8;
        case 100:
            return 9;
        default:
            return -1;
    }
}

void initStack(){
    for(int i=0;i< STACK_SIZE ;i++)
        stack[i]='\0';
    sIndex=0;
    push('$');
    push('E');
}

void getATemp(){
    Pt_Word pt_word=scanner(program);
    aTemp=yindex(pt_word->wordType);
    if(pt_word->wordType != -1){
        if(pt_word->wordType==20) printf("( %d , %e )\n",20,c2d(pt_word->word));
        else printf("( %d , %s )\n",pt_word->wordType,pt_word->word);
        printf("当前的a为%s\n",pt_word->word);
    }
}

void getSTopElement(){
    sTopElement=pop();
    printf("当前的栈顶为%c\n",sTopElement);
}

void endInfo(bool suc){
    if(suc){
        printf("分析完成，成功\n");
    }else{
        printf("分析完成，错误\n");
    }

}

void pushByTable(int nt,int t){
    switch (nt){
        case 0:
            switch (t){
                case 4:
                    push('A');
                    push('T');
                    break;
                case 6:
                    push('A');
                    push('T');
                    break;
                case 8:
                    push('A');
                    push('T');
                    break;
            }
            break;
        case 1:
            switch (t){
                case 0:
                    push('A');
                    push('T');
                    push('+');
                    break;
                case 1:
                    push('A');
                    push('T');
                    push('-');
                    break;
                case 5:
                case 7:
                case 9:
                    break;
            }
            break;
        case 2:
            switch (t){
                case 4:
                case 6:
                case 8:
                    push('B');
                    push('F');
                    break;
            }
            break;
        case 3:
            switch (t){
                case 2:
                    push('B');
                    push('F');
                    push('*');
                    break;
                case 3:
                    push('B');
                    push('F');
                    push('/');
                    break;
                case 0:
                case 1:
                case 5:
                case 9:
                case 7:
                    break;
            }
            break;
        case 4:
            switch (t){
                case 4:
                    push(')');
                    push('E');
                    push('(');
                    break;
                case 6:
                    push('i');
                    break;
                case 8:
                    push('n');
                    break;
            }

    }
}



void analyse(){
    initStack();
    getATemp();
    while (1){
        getSTopElement();
        if(isNterms(sTopElement)){
            if(sTopElement=='$'){
                int sInt= c2i(sTopElement);
                if(sInt!=aTemp) {
                    endInfo(false);
                    break;
                }else{
                    endInfo(true);
                    break;
                }
            }else{
                int sInt= c2i(sTopElement);
                if(table[sInt][aTemp]==1){
                    pushByTable(sInt,aTemp);
                }else{
                    endInfo(false);
                    break;
                }
            }
        }
        // 如果是终结符，就需要获取到终结符在表中的顺序
        else{
            int sInt= ct2i(sTopElement);
            if(sInt!=aTemp){
                endInfo(false);
                break;
            } else getATemp();
            /*while(aTemp!=sInt){
                error();
                getATemp();
            }
            // 如果两者相等，就将两个抛弃
            pop();
            getATemp();*/
        }
    }
}

