#include <iostream>
#include "scanner.h"

int main() {
    for(int i=0;i< PROGRAME_SIZE ;i++)
        program[i]='\0';
    printf("input a program\n");
    fgets(reprogram,PROGRAME_SIZE,stdin);
    init();
    printf("%s\n",program);
    while(program[key]!='#' && program[key]!='$' && program[key]!='\0'){
        Pt_Word pt_word=scanner(program);
        if(pt_word != NULL)
        printf("( %d , %s )\n",pt_word->wordType,pt_word->word);
    }
    return 0;
}