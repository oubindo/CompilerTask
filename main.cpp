#include <iostream>
#include "scanner.h"
#include "recursive.h"
#include "mean.h"

/*char* get(){
    char nu[]="I am oubindo";
    char* c=(char *)malloc(sizeof(char)*20);
    c=nu;
    return c;
}*/



int main() {
    char c;
    int s=0;
    for(int i=0;i< PROGRAME_SIZE ;i++){
        reprogram[i]='\0';
        exprogram[i]='\0';
        program[i]='\0';
    }
    printf("input a program\n");
    while((c=getchar())!='$'){
        reprogram[s++]=c;
    }
    init();
    printf("%s\n",program);
    //analyse();
    recursive();
   /* while(ch!='$'){
        Pt_Word  pt_word=scanner(program);
        if(pt_word->wordType!=-1){
            if(pt_word->wordType==20) printf("( %d , %e )\n",20,c2d(pt_word->word));
            else printf("( %d , %s )\n",pt_word->wordType,pt_word->word);
        }
    }*/

    return 0;
}