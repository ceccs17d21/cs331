#include<stdio.h>
#include<stdlib.h>

int pro[10],no_s,initial_p,t_st,dir,done[]={0,0,0,0,0,0,0,0,0,0};
//   0 -->, 1 <--
int shortest_seek(int p){
    int i,temp=201,proc=-1;
    if(dir==0){
        for(i=0;i<no_s;i++){
            if(abs(p-pro[i])<temp && done[i]!=0 && pro[i]>=p){
                temp=abs(p-pro[i]);
                proc=i;
            }
        }
        if(temp == 201){
            dir =1;
        }
    }
    else{
        for(i=0;i<no_s;i++){
            if(abs(p-pro[i])<temp && done[i]!=0 && pro[i]<=p){
                temp=abs(p-pro[i]);
                proc=i;
            }
        }
        if(temp == 201){
            dir=0;
        }       
    }
    return proc;    //done[proc]=1 is seted in scan()
}
void fcfs(){
    int i,cur_p=initial_p;
    t_st=0;
    for(i=0;i<no_s;i++){
        t_st+=abs(cur_p-pro[i]);
        cur_p = pro[i];
        printf("\nP%d  %d",i+1,pro[i]);
    }
    printf("seek time: %d",t_st);
}

void set_direction(){
    int i,temp=201,proc;
    for(i=0;i<no_s;i++){
        if(abs(initial_p-pro[i])<temp){
            temp=abs(initial_p-pro[i]);
            proc = i;
        }
        if(pro[proc]<initial_p){
            dir=1;
        }else {
            dir=0;
        }
    }
}

void scan(){
    int flag=0,i,short_s,short_p,cur_p=initial_p;
    t_st=0;
    set_direction();
    printf("dda");
    while(flag<no_s){  
        short_p = shortest_seek(cur_p);
        if(short_p==-1){
            if(dir==0){
                t_st = 199 - cur_p;
                cur_p = 199;
            }
            else{
                t_st = cur_p - 0;
                cur_p = 0;
            }
        }
        else{
            t_st= abs(cur_p-pro[short_p]);
            cur_p = pro[short_p];
            flag+=1;
            printf("P%d : %d",short_p+1,cur_p);
        }
   
    }    
    printf("\nSeek time: %d",t_st);    
}

void main(){
    int i,ch;
    printf("\nLIMIT = 200");
    printf("\nEnter the no of seek: ");
    scanf("%d",&no_s);
    printf("\nInitial location: ");
    scanf("%d",&initial_p);

    for(i=0;i<no_s;i++){
        scanf("%d",&pro[i]);
    }

    printf("MENU\n1. FCFS\n2. SCAN\n3. CSCAN\n4. Exit\nChoice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            fcfs();
            break;
        case 2:
            scan();
            break;
        case 3:
            //cscan();
            break;
    }
    
}
