#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* input file format

TEST     START      2000
-        MOV        BETA
.
.
BETA     RESW       2
.
-        END        -
(labelbel)  (Opcode)   (operand)   

   intermediate file format

TEST    START    2000
2000    -        MOV     BETA     
.
.
2036    BETA     RESW    2
.
2048    -        END
*/

void main() {
    int loc,start_addr,l,operand,o,len;
    char opcode[20],label[20],op[20],oper[20];
    FILE *in_ptr,*opt,*symt;
    in_ptr=fopen("input.txt","r");
    symt=fopen("symtab.txt","w");

    fscanf(in_ptr,"%s %s %d",label,opcode,&operand);
    if(strcmp(opcode,"START")==0) {
        start_addr=operand;
        loc=start_addr;
        printf("\t%s\t%s\t%d\n",label,opcode,operand);
    }
    else
        loc=0;

    fscanf(in_ptr,"%s %s",label,opcode);
    while(!feof(in_ptr)) {
        fscanf(in_ptr,"%s",op);
        printf("%d\t%s\t%s\t%s\n",loc,label,opcode,op);
        if(strcmp(label,"-")!=0) {
            fprintf(symt,"\n%d\t%s\n",loc,label);
        }
        opt=fopen("optab.txt","r");
        fscanf(opt,"%s %d",oper,&o);
        while(!feof(opt)) {
            if(strcmp(opcode,oper)==0){
                loc=loc+3;
                break;
            }
            fscanf(opt,"%s %d",oper,&o);
        }
        fclose(opt);

        if(strcmp(opcode,"RESW")==0) {
            operand=atoi(op);
            loc=loc+(3*operand);
        }
        else if(strcmp(opcode,"WORD")==0) {
            loc=loc+3;
        }
        else if(strcmp(opcode,"BYTE")==0)
        {
            if(op[0]=='X')
                loc=loc+1;
            else{
                len=strlen(op)-2;
                loc=loc+len;
            }
        }
        else if(strcmp(opcode,"RESB")==0) {
            operand=atoi(op);
            loc=loc+operand;
        }
        fscanf(in_ptr,"%s%s",label,opcode);
    }
    if(strcmp(opcode,"END")==0) {
        printf("SIZE\t%d\n",loc - start_addr);
    }
    fclose(in_ptr);
    fclose(symt);
}