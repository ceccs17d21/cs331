#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
    int i;
    char label[20],opcode[20],operand[20],loc[20],start[20],len[20],opc[20],mne[20],symadr[20],sym[20];
    FILE *opt,*syt,*imf,*siz;

    imf = fopen("inter_file.txt","r");
    opt = fopen("optab.txt","r");
    syt = fopen("symtab.txt","r");
    siz = fopen("size.txt","r");

    fscanf(imf,"%s%s%s%s",loc,label,opcode,operand);
    if(strcmp(opcode,"START") == 0){
        strcpy(start,operand);
        fscanf(siz,"%s",len);
        printf("H^%s^%s^%s\n",label,start,len);
    }
    fscanf(imf,"%s%s%s%s",loc,label,opcode,operand);
    while(strcmp(opcode,"END") != 0 ){
        printf("T^00%s^",loc);
        while ( !feof(opt) ){
            fscanf(opt,"%s%s",mne,opc);
            if (strcmp(opcode,mne) ==0 ){
                printf("%s",opc);
                while ( !feof(syt) ){
                    fscanf(syt,"%s%s",symadr,sym);
                    if (strcmp(sym,operand) ==0 ){
                    printf("%s^\n",symadr);
                    break;
                    }
                }
            }
        }    
        if(strcmp(opcode,"BYTE") == 0){
            for(i=2;i<strlen(operand);i++){
                printf("%d",operand[i]);
            }
            printf("\n");
        }
        else if(strcmp(opcode,"WORD" ) == 0 || strcmp(opcode,"RESB" ) == 0 || strcmp(opcode,"RESW" ) == 0){
            printf("0000%s^\n",operand);
        }
        fseek(syt,SEEK_SET,0);
        fseek(opt,SEEK_SET,0);
        fscanf(imf,"%s%s%s%s",loc,label,opcode,operand);
    }
    printf("E^00%s\n",start);
    fclose(imf);
    fclose(opt);
    fclose(syt);
    fclose(siz);
}