#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int LIMIT = 10;

struct dir_s{
    int no_files;
    char f_name[10][10];
}folder[10];

struct dir_h{
	char dir_name[10];
	char fname[10][10];
	int no_files,no_subd;
	struct dir_h *sub_dir[10];
};
void initialize(struct dir_h *x){
	int i;
	x->no_files=0;
	x->no_subd=0;
	for(i=0;i<LIMIT;i++){
		x->sub_dir[i]=NULL;
	}
}
struct dir_h* search_dir(struct dir_h *cur_dir,char dir_name[10]){
	int i;
	//struct dir *temp;
	for(i=0;i<cur_dir->no_subd;i++){
		if(!strcmp(dir_name,cur_dir->sub_dir[i]->dir_name)){
			return cur_dir->sub_dir[i];
		}
	}
	return NULL;
}
int search_dir_index(struct dir_h *cur_dir,char dir_name[10]){
	int i;
	//struct dir *temp;
	for(i=0;i<cur_dir->no_subd;i++){
		if(!strcmp(dir_name,cur_dir->sub_dir[i]->dir_name)){
			return i;
		}
	}
	return -1;
}
int check(struct dir_h *curr_dir,char f_nm[]){
    int i;
    for(i=0;i<curr_dir->no_files;i++)
        if(!strcmp(f_nm,curr_dir->fname[i]))
            return 1;
    return 0;
}
int check_s(char f_nm[]){
    int i;
    for(i=0;i<folder[0].no_files;i++)
        if(!strcmp(f_nm,folder[0].f_name[i]))
            return 1;
    return 0;
}
int check_tw(int dir_index,char f_nm[]){
    int i;
    for(i=0;i<folder[dir_index].no_files;i++)
        if(!strcmp(f_nm,folder[dir_index].f_name[i]))
            return 1;
    return 0;
}

void main(){
    int choice,c=1,i,flag=0,file_sys;
    char f_nm[10];
    int j,dir_index=0;
	int temp_i,cho=0;
	char dir_name[10],head_name[]="root";
    struct dir_h *head,*temp,*current_dir;
    folder[0].no_files=0;
    printf("\nMENU\n1.Single level\n2.Two level\n3.Hierarchical\n4.Exit\nchoice: ");
    scanf("%d",&file_sys);
    switch(file_sys){
        case 1:
            do{
                printf("MENU\n1.Create_File\n2.Delete_File\n3.Traverse\n4.Search_File\nChoice: ");
                scanf("%d",&choice);
                switch(choice){
                    case 1: if(folder[0].no_files<LIMIT){
                                trace_rename_s:
                                printf("File name(max: 10char): ");
                                scanf("%s",f_nm);
                                if(check_s(f_nm)){
                                    printf("File already exists!!! Try another name\n");
                                    goto trace_rename_s;
                                }
                                else{
                                    strcpy(folder[0].f_name[folder[0].no_files],f_nm);
                                    folder[0].no_files++;
                                }
                            }else
                                printf("No more space!!!");
                            break;
                    case 2: if(folder[0].no_files>0){
                                printf("File name(max: 10char): ");
                                scanf("%s",f_nm);
                                for(i=0;i<folder[0].no_files;i++){
                                    if(!strcmp(folder[0].f_name[i],f_nm)){
                                        flag=1;                    
                                        folder[0].no_files--;
                                    }
                                    if(flag==1){
                                        strcpy(folder[0].f_name[i],folder[0].f_name[i+1]);
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
                            for(i=0;i<folder[0].no_files;i++)
                                printf("->%d        %s\n",i,folder[0].f_name[i]);
                            break;
                    case 4: printf("File name: ");
                            scanf("%s",f_nm);
                            for(i=0;i<folder[0].no_files;i++)
                                if(!strcmp(f_nm,folder[0].f_name[i])){
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
            break;
        case 2:
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
                                if(check_tw(dir_index,f_nm)){
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
        break;
        case 3:
            head = (struct dir_h*)malloc(sizeof(struct dir_h));
            strcpy(head->dir_name,head_name);
            current_dir = head;
	        initialize(head);
            do{
                printf("\nMENU\n1.Change_dir\n2.Create_dir\n3.Rmv_dir\n4.Create_file\n5.Delete_file\n6.Traverse\n7.Search_file\n8.Back to root\n9.Current_dir\nChoice: ");
                scanf("%d",&choice);
                switch(choice){
                    case 1: printf("Current_dir: %s",current_dir->dir_name);
                            printf("\nEnter dir_name (max 10char): ");
                            scanf("%s",dir_name);
                            if(current_dir->no_subd==0)
                                printf("\nNo sub_dirs!!!");
                            else {
                                temp=search_dir(current_dir,dir_name);
                                current_dir = temp;
                            }
                            break;
                    case 2: printf("Enter dir_name: ");
                            scanf("%s",dir_name);
                            if(current_dir->no_subd<LIMIT){
                                temp = (struct dir_h*)malloc(sizeof(struct dir_h));
                                initialize(temp);
                                current_dir->sub_dir[current_dir->no_subd]=temp;
                                strcpy(temp->dir_name,dir_name);
                                current_dir->no_subd +=1;
                            }
                            else
                                printf("No Space!!!");
                            break;
                    case 3: printf("Enter dir_name: ");
                            scanf("%s",dir_name);
                            temp_i= search_dir_index(current_dir,dir_name);
                            if(temp_i==-1)
                                printf("dir doesn't exist!!!");
                            else{
                                temp=current_dir->sub_dir[temp_i];
                                free(temp);
                                current_dir->sub_dir[temp_i]=NULL;
                                current_dir->no_subd -= 1;
                            }
                            break;
                    case 4: if(current_dir->no_files<LIMIT){
                                trace_rename_h:
                                printf("File name(max: 10char): ");
                                scanf("%s",f_nm);
                                if(check(current_dir,f_nm)){
                                    printf("File already exists!!! Try another name\n");
                                    goto trace_rename_h;
                                }
                                else{
                                    strcpy(current_dir->fname[current_dir->no_files],f_nm);
                                    current_dir->no_files++;
                                }
                            }else
                                printf("No more space!!!");
                            break;
                    case 5: if(current_dir->no_files>0){
                                printf("File name(max: 10char): ");
                                scanf("%s",f_nm);
                                for(i=0;i<current_dir->no_files;i++){
                                    if(!strcmp(current_dir->fname[i],f_nm)){
                                        flag=1;                    
                                        current_dir->no_files--;
                                    }
                                    if(flag==1){
                                        strcpy(current_dir->fname[i],current_dir->fname[i+1]);
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
                    case 6: printf("\nPostion   Name\n");
                            for(i=0;i<current_dir->no_files;i++)
                                printf("->%d        %s\n",i,current_dir->fname[i]);
                            break;
                    case 7: printf("File name: ");
                            scanf("%s",f_nm);
                            for(i=0;i<current_dir->no_files;i++)
                                if(!strcmp(f_nm,current_dir->fname[i])){
                                    printf("File found at (%d)",i);
                                    flag=1;
                                }
                            if(flag==0)
                                printf("File not found!!!");
                            else
                                flag=0;
                            break;
                    case 8: current_dir=head;
                            break;
                    case 9: printf("%s",current_dir->dir_name);
                }
                printf("\npress 1 to continue!");
                scanf("%d",&cho);
            }while(cho==1);
        break;
    }

}