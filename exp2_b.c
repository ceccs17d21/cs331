#include<stdio.h>
#include<string.h>

int LIMIT = 10;

struct dir{
    int no_files;
    char f_name[10][10];
}folder[10];

int check(int dir_index,char f_nm[]){
    int i;
    for(i=0;i<folder[dir_index].no_files;i++)
        if(!strcmp(f_nm,folder[dir_index].f_name[i]))
            return 1;
    return 0;
}

void main(){   
    int choice,c=1,i,j,flag=0,dir_index=0;
    char f_nm[10];
    for(i=0;i<LIMIT;i++)
        folder[i].no_files=0;
    do{
        printf("MENU\n1.Create_File\n2.Delete_File\n3.Traverse\n4.Search_File\nChoice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Choose directory (0-9): ");
                    scanf("%d",&dir_index);
                    if(folder[dir_index].no_files<LIMIT){
                        trace_rename:
                        printf("File name(max: 10char): ");
                        scanf("%s",f_nm);
                        if(check(dir_index,f_nm)){
                            printf("File already exists!!! Try another name\n");
                            goto trace_rename;
                        }
                        else{
                            strcpy(folder[dir_index].f_name[folder[dir_index].no_files],f_nm);
                            folder[dir_index].no_files++;
                        }
                    }else
                        printf("No more space!!!");
                    break;
            case 2: printf("Choose directory (0-9): ");
                    scanf("%d",&dir_index);
                    if(folder[dir_index].no_files>0){
                        printf("File name(max: 10char): ");
                        scanf("%s",f_nm);
                        for(i=0;i<folder[dir_index].no_files;i++){
                            if(!strcmp(folder[dir_index].f_name[i],f_nm)){
                                flag=1;                    
                                folder[dir_index].no_files--;
                            }
                            if(flag==1){
                                strcpy(folder[dir_index].f_name[i],folder[dir_index].f_name[i+1]);
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
            case 3: for(j=0;j<LIMIT;j++){                        
                        printf("Dir %d\n",j);
                        for(i=0;i<folder[j].no_files;i++)
                            printf("   ->%d        %s\n",i,folder[j].f_name[i]);
                    }
                    break;
            case 4: printf("Choose directory (0-9): ");
                    scanf("%d",&dir_index);
                    printf("File name: ");
                    scanf("%s",f_nm);
                    for(i=0;i<folder[dir_index].no_files;i++)
                        if(!strcmp(f_nm,folder[dir_index].f_name[i])){
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