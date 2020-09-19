#ifndef _stdiodef_
#include <stdio.h>
#define _stdiodef_
#endif
#ifndef _stdlibdef_
#include <stdlib.h>
#define _stdlibdef_
#endif
#ifndef _stringdef_
#include <string.h>
#define _stringdef_
#endif

FILE *fp; //전역변수 초기화

int menu(void){
    int que;
    puts("\n******MENU******\n");
    puts("1. Insert\n");
    puts("2. Delete\n");
    puts("3. Search\n");
    puts("4. Print All\n");
    puts("5. Exit\n");
    printf  ("Choose the item: ");
    scanf("%d", &que);

    return que;
}
void case1(void){
    char name[20], phonenum[20];
    fseek(fp, 0, SEEK_END);
    puts("\n[ INSERT ]\n");
    printf("Input Name: ");
    scanf("%s", name);
    printf("Input Tel Number: ");
    scanf("%s", phonenum);
    fprintf(fp, "\n%s %s", name, phonenum);
    puts("\n[ Data Inserted ]\n");
}

void case2(void){
    int size1, size2, except, end;
    char name[50], temp1[50], temp2[50];
    puts("\n[ Delete Data ]\n");
    printf("Input Name: ");
    scanf("%s", name);

    fseek(fp, 0, SEEK_SET);

    while(!feof(fp)){
        size1 = ftell(fp);
        fscanf(fp, "%s", temp1);
        fscanf(fp, "%s", temp2);
        size2 = ftell(fp);
        if(!strcmp(name, temp1)){
            FILE *temp = fopen("temp.txt", "wt");
            fseek(fp, 0, SEEK_END);
            end = ftell(fp);
            fseek(fp, 0, SEEK_SET);
            fseek(temp, 0, SEEK_SET);
            while(ftell(fp) != size1){
                fputc(fgetc(fp), temp);
            }
            fseek(fp, size2, SEEK_SET);
            while(ftell(fp) != end){
                fputc(fgetc(fp), temp);                
            }
            fclose(fp);
            except = remove("note.txt");
            if(except != 0){
                printf("\n[ Deleting Data Fail ]\n\n");
                return;
                
            }
            fclose(temp);
            except = rename("temp.txt", "note.txt");
            if(except != 0){
                puts("\n[ Deleting Data Fail ]\n");
                return;
            }
            fp = fopen("note.txt", "r+t");
            puts("\n[ Data Deleted ]\n");
            return;  
        }
    }
    puts("\n[ Searching Name failed ]\n");
}

void case3(void){
    char name[50], temp1[50], temp2[50];
    fseek(fp, 0, SEEK_SET);

    puts("\n[ Search Data ]\n");
    printf("Input Name: ");
    scanf("%s", name);

    while(!feof(fp)){
        fscanf(fp, "%s", temp1);
        fscanf(fp, "%s", temp2);
        if(!strcmp(name, temp1)){
            puts("\n[ Data Searched ]\n");       
            printf("Name: %s    Tel: %s\n", temp1, temp2);
            return;  
        }
    }
    puts("\n[ Searching Name failed ]\n");
}

void case4(void){
    char name[50], phonenum[50];

    puts("\n[ Print All Data ]\n");
    fseek(fp, 0, SEEK_SET);
    while(!feof(fp)){ 

        memset(name, 0, 50);
        memset(phonenum, 0, 50);
        fscanf(fp, "%s", name);
        fscanf(fp, "%s", phonenum);
        if(!strcmp(name, phonenum)){
            puts("\n[ No Data ]\n");
            return;
        }
        printf("Name: %s    Tel: %s\n", name, phonenum);
    }
}