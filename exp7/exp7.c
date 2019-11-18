#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(){
    FILE *inp_f,*optab,*symtab,*ser_sym;
    int loc=0,flag,flag_op,size,prev_loc,start_addr;
    char label[20],opcode[20],operand[20],symbol[20],op[20],obc[20],symbol_loc[20];

    inp_f = fopen("input.txt","r");
    symtab = fopen("symtab.txt","w");
    optab = fopen("optab.txt","r");
    ser_sym = fopen("symtab.txt","r");

    fscanf(inp_f,"%s %s %s",label,opcode,operand);
    if (strcmp(opcode,"START")==0){
        loc = atol(operand);
        printf("\t%s\t%s\t%s\n",label,opcode,operand);
        fscanf(inp_f,"%s %s %s",label,opcode,operand);  
    }
    else
        loc = 0;
    start_addr = loc;

    while (strcmp(opcode,"END") != 0 || !feof(inp_f)){
        prev_loc = loc;
        if( strcmp(label,"#") != 0 ){                //considers single line comments only
            if (strcmp(label,"-") != 0){               
                fscanf(ser_sym,"%s %s",symbol,symbol_loc);
                flag=0;
                while ( !feof(ser_sym)){
                    fscanf(ser_sym,"%s %s",symbol,symbol_loc);
                    if (strcmp(label,symbol) == 0)
                        flag++;
                }
                if (flag == 0){
                    fprintf(symtab,"%s\t%d\n",label,loc);
                }
            }
            // search optab
            fscanf(optab,"%s %s",op,obc);
            flag_op = 0;
            
            while( !feof(optab)){
                fscanf(optab,"%s %s",op,obc);
                if (strcmp(op,opcode) == 0)
                    flag_op ++;
            }
            if (flag_op == 0)
                loc += 3;

            // if opcode not in optab
            if (strcmp(opcode,"WORD") == 0)
                loc += 3;
            else if (strcmp(opcode,"RESB") == 0){
                size = atol(operand);
                loc += size;
            }
            else if (strcmp(opcode,"RESW") == 0){
                size = atol(operand);
                loc += size*3;
            }
            else if (strcmp(opcode,"BYTE") == 0){
                size = strlen(operand);
                loc += size;
            }      
        
            printf("%d\t%s\t%s\t%s\n", prev_loc,label,opcode,operand);
        } // end of comment
        else
            loc += 3;
        fseek(ser_sym,SEEK_SET,0);
        fseek(optab,SEEK_SET,0);
        fscanf(inp_f,"%s %s %s",label,opcode,operand);  
    } // end of while

    printf("%d\t%s\t%s\n\n", loc,operand,opcode);
    printf("SIZE\t%d\n",loc-start_addr);
    fclose(inp_f);
    fclose(symtab);
    fclose(optab);
    fclose(ser_sym);
}










