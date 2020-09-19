#ifndef _funcdef_
#include "func.h"
#endif
#ifndef _stdiodef_
#include <stdio.h>
#endif
#ifndef _stdlibdef_
#include <stdlib.h>
#endif
#ifndef _stringdef_
#include <string.h>
#endif

FILE *fp; //전역변수 초기화

int main(void){
    fp = fopen("note.txt", "r+t");
    if(fp == NULL){
        fclose(fp);
        fp = fopen("note.txt", "w");
        fclose(fp);
        fp = fopen("note.txt", "r+t");
    }
    int temp;
    while(1){
        temp = menu();
        if(temp <= 5 && temp >= 1){
            switch(temp){
                case 1:
                    case1();
                    break;
                case 2:
                    case2();
                    break;
                case 3:
                    case3();
                    break;
                case 4:
                    case4();
                    break;
                case 5:
                    return 0;
            }
        }
    }  
}