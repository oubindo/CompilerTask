//
// Created by oubin on 16-11-28.
//
#include <cstring>
#include <malloc.h>
#include "scanner.h"

char const *keywords[]={"main","int","float","double","char","if","else","do","while"};
char program[PROGRAME_SIZE];
char reprogram[PROGRAME_SIZE];
char exprogram[PROGRAME_SIZE];
char token[TOKEN_SIZE];
char ch;
bool isUseful=true;
int key=0;
int aIndex=0;

void initExp(){
    int j=0;
    for(int i=0;i<PROGRAME_SIZE;i++){
        char c=reprogram[i];
        if(c=='/' && reprogram[i+1]=='*'){
            isUseful=false;
        }
        if(isUseful){
            if(c!= '\r' && c !='\n'&& c!='\t'){
                exprogram[j++]=c;
            }
        }
        if(i>=1 && reprogram[i-1]=='*' && c=='/') isUseful=true;
    }
}


void initSpace(){
    int j=0;
    for(int i=0;i<PROGRAME_SIZE && exprogram[i] != '\0';){
        char c=exprogram[i];
        while(c==' ' && exprogram[i+1]==' '){
            i++;
        }
        program[j++]=exprogram[i++];
    }
    program[j]='$';
}

void init(){
    initExp();
    initSpace();
}

double c2d(char *s){
    double d1=0,d2=0;
    int t=0;
    int i=0;
    bool operation=true;
    bool isNag=false;

    if(s[i]=='+'){
        isNag=false;
        i++;
    }else if(s[i]=='-'){
        isNag=true;
        i++;
    }else if(isDigit(s[i])){
        isNag=false;
    }

    while(s[i]!='\0' && s[i]!='e'){
        if(s[i]=='.'){
            t=10;
        }else{
            if(t==0){
                d1=d1*10 + (s[i]-'0');
            }else{
                d1 = d1 + (double)(s[i]-'0')/t;
                t *=10;
            }

        }
        i++;
    }

    if(s[i]=='e'){
        if(s[i+1]=='+' || isDigit(s[i+1])) {
            operation=true;
            if(s[i+1]=='+'){
                d2=dealNorm(s,i+2);
            }else{
                d2=dealNorm(s,i+1);
            }
        }
        else if(s[i+1]=='-'){
            operation=false;
            if(s[i+1]=='-'){
                d2=dealNorm(s,i+2);
            }else{
                d2=dealNorm(s,i+1);
            }
        }
    }

    if(operation){
        while(d2>=1){
            d1=d1*10;
            d2--;
        }
    }else{
        while(d2<=-1){
            d1=d1/10;
            d2++;
        }
    }

    if(isNag){
        d1=0-d1;
    }
    return d1;
}

double dealNorm(char *s,int i){
    int d1=0;
    while(s[i]!='\0'){
        d1=d1*10 + (s[i]-'0');
        i++;
    }
    return d1;
}


char getch(char *str){
    ch=*(str+key);
    key++;
}

void getbc(char *str){
    // 空格回车换行符预处理
    while(ch == ' ' || ch== '\r' || ch =='\n'|| ch=='\t'){
        getch(str);
    }
}

void empty(){
    for(int i=0;i< TOKEN_SIZE ;i++)
        token[i]='\0';
    aIndex=0;
}

void concat(){
    token[aIndex++]=ch;
}

bool isLetter(char ch){
    if((ch>='a' && ch <= 'z') || (ch>='A' && ch<='Z')) return true;
    else return false;
}

bool isDigit(char ch){
    if(ch>='0' && ch<='9') return true;
    else return false;
}

int reserve(){
    for(int i=0;i<9;i++){
        if(strcmp(token,*(keywords+i))==0) return i+1;
    }
    return SIGN_WORD;
}

void retract(){
    if(key>0){
        key--;
    }
}

Pt_Word resultWord(int type, char *c){
    Pt_Word pt_word=(Pt_Word)malloc(sizeof(Word));
    pt_word->word=c;
    pt_word->wordType=type;
    return pt_word;
}

int dtb();

void error(){
    printf("error token %s\n",token);
}


Pt_Word testDigit(char *str){
    // 删除了一个getch修正3的情况
    if(ch=='+' || ch == '-'){
        concat();
        getch(str);
    }
    while(isDigit(ch)){
        concat();
        getch(str);
        if(ch !='.' && ch!= 'e' && !isDigit(ch)){
            retract();
            return resultWord(20, token);
        }
    }
    if(ch== '.'){
        concat();
        getch(str);
        if(!isDigit(ch)){
            error();
            retract();
            return resultWord(-1,"error");
        }
        while(isDigit(ch)){
            concat();
            getch(str);
            if(ch!= 'e' && !isDigit(ch)){
                retract();
                return resultWord(20, token);
            }
        }
        if(ch=='e'){
            concat();
            getch(str);
            while(isDigit(ch)){
                concat();
                getch(str);
                if(!isDigit(ch)){
                    retract();
                    return resultWord(20, token);
                }
            }
            if(ch=='+' || ch == '-'){
                concat();           // 加入了concat()来修补e后面没有+-的情况
                getch(str);
                if(isDigit(ch)){
                    retract();
                    getch(str);
                    while(isDigit(ch)){
                        concat();
                        getch(str);
                    }
                    retract();
                    return resultWord(20, token);
                }
            }
        }
    }else if(ch == 'e') {
        concat();
        getch(str);
        while (isDigit(ch)) {
            concat();
            getch(str);
            if (!isDigit(ch))
                retract();
                return resultWord(20, token);
        }
        if (ch == '+' || ch == '-') {
            concat();
            getch(str);
            if (isDigit(ch)) {
                retract();
                getch(str);
                while (isDigit(ch)) {
                    concat();
                    getch(str);
                }
                retract();
                return resultWord(20, token);
            }
        }
    }
    error();
    retract();
    return resultWord(-1,"error");
}


Pt_Word scanner(char *str){
    empty();
    getch(str);
    getbc(str);
    if(isLetter(ch)){
        while(isLetter(ch) || isDigit(ch)){
            concat();
            getch(str);
        }
        retract();
        int type=reserve();
        if(type != 10) return resultWord(type, token);
        else return resultWord(10,token);
    } else if(isDigit(ch)){
        return testDigit(str);
    } else switch(ch){
            case '+':
                getch(str);
                if(isDigit(ch)){
                    retract();
                    retract();
                    if(key == 0){
                        getch(str);
                        return testDigit(str);
                    } else {
                        retract();
                        getch(str);
                        if(isDigit(ch) || isLetter(ch)){
                            getch(str);
                            return resultWord(22, "+");
                        } else {
                            getch(str);
                            return testDigit(str);
                        }
                    }
                }
                retract();
                return resultWord(22, "+");
            case '-':
                getch(str);
                if(isDigit(ch)){
                    retract();
                    retract();                  // 添加了一个retract修正-3的情况
                    if(key == 0){
                        getch(str);             // 添加了一个getch修正-3的情况
                        return testDigit(str);
                    } else{
                        retract();
                        getch(str);
                        if(isDigit(ch) || isLetter(ch)){   // 加入isLetter修正表达式的情况
                            getch(str);
                            return resultWord(23, "-");
                        }else{
                            getch(str);
                            return testDigit(str);
                        }
                    }
                }
                retract();
                return resultWord(23, "-");
                // 下面这些作为二目运算符都没问题
            case '*': return resultWord(24, "*");
            case '/': return resultWord(25, "/");
            case '(': return resultWord(26, "(");
            case ')': return resultWord(27, ")");
            case '{': return resultWord(28, "{");
            case '}': return resultWord(29, "}");
            case ',': return resultWord(30, ",");
            case ';': return resultWord(31, ";");
            case '#': return resultWord(0, "#");
            case '$': return resultWord(100,"$");
            case '=':
                getch(str);
                if(ch == '=') return resultWord(36, "==");
                else{
                    retract();
                    return resultWord(21, "=");
                }
            case '>':
                getch(str);
                if(ch == '=') return resultWord(33, ">=");
                else{
                    retract();
                    return resultWord(32, ">");
                }
            case '<':
                getch(str);
                if(ch == '=') return resultWord(35, "<=");
                else{
                    retract();
                    return resultWord(34, "<");
                }
            case '!':
                getch(str);
                if(ch == '=') return resultWord(37, "!=");
                else {
                    retract();
                    error();
                }
                break;
            default:
                concat();
                break;
        }
    error();
    return resultWord(-1,"error");
}



