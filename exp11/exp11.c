#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
    FILE *inp;
    char type[1],objc[7],part1[3],part2[3],part3[3];
    int loc;
    inp = fopen("input.txt","r");
    fscanf(inp,"%s",objc);
    while( !feof(inp) || strcmp(objc,"E") != 0){
        if(strcmp(objc,"T") == 0){
            fscanf(inp,"%s",objc);
            loc = atoi(objc);
            while( !feof(inp) ){
                fscanf(inp,"%s",objc);
                if(strcmp(objc,"E") == 0 ||strcmp(objc,"T") == 0 )
                    break;
                part1[0]=objc[0]; part1[1]=objc[1]; part1[2]='\0';
                part2[0]=objc[2]; part2[1]=objc[3]; part2[2]='\0';
                part3[0]=objc[4]; part3[1]=objc[5]; part3[2]='\0';
                printf("%d\t%s\n",loc++,part1);
                printf("%d\t%s\n",loc++,part2);
                printf("%d\t%s\n",loc++,part3);

            }
            if(strcmp(objc,"E") == 0)
                break;
        }
        else
            fscanf(inp,"%s",objc);

    }
    fclose(inp);
}