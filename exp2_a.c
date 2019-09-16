#include<stdio.h>
#include<string.h>

int LIMIT = 10;

struct dir{
    int no_files;
    char f_name[10][10];
}folder;

int check(char f_nm[]){
    int i;
    for(i=0;i<folder.no_files;i++)
        if(!strcmp(f_nm,folder.f_name[i]))
            return 1;
    return 0;
}

void main(){
    folder.no_files=0;
    int choice,c=1,i,flag=0;
    char f_nm[10];
    do{
        printf("MENU\n1.Create_File\n2.Delete_File\n3.Traverse\n4.Search_File\nChoice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: if(folder.no_files<LIMIT){
                        trace_rename:
                        printf("File name(max: 10char): ");
                        scanf("%s",f_nm);
                        if(check(f_nm)){
                            printf("File already exists!!! Try another name\n");
                            goto trace_rename;
                        }
                        else{
                            strcpy(folder.f_name[folder.no_files],f_nm);
                            folder.no_files++;
                        }
                    }else
                        printf("No more space!!!");
                    break;
            case 2: if(folder.no_files>0){
                        printf("File name(max: 10char): ");
                        scanf("%s",f_nm);
                        for(i=0;i<folder.no_files;i++){
                            if(!strcmp(folder.f_name[i],f_nm)){
                                flag=1;                    
                                folder.no_files--;
                            }
                            if(flag==1){
                                strcpy(folder.f_name[i],folder.f_name[i+1]);
                            }
                        }
                        if(flag==0){
                            printf("file not Found!!!");
                        }
                        else{
                            printf("1 file deleted!!!");
                            flag=0;
                        }
                    }
                    else
                        printf("Empty folder!!!");
                    break;
            case 3: printf("\nPostion   Name\n");
                    for(i=0;i<folder.no_files;i++)
                        printf("->%d        %s\n",i,folder.f_name[i]);
                    break;
            case 4: printf("File name: ");
                    scanf("%s",f_nm);
                    for(i=0;i<folder.no_files;i++)
                        if(!strcmp(f_nm,folder.f_name[i])){
                            printf("File found at (%d)",i);
                            flag=1;
                        }
                    if(flag==0)
                        printf("File not found!!!");
                    else
                        flag=0;
                    break;

        }
        printf("\nPress 1 to continue!!!: ");
        scanf("%d",&c);
    }while(c==1);
}