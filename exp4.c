#include<stdio.h>
#include<stdlib.h>

int no_s,pro[10],initial_p,dir,t_st,i;

void ase_sort(int a[],int size){
    int temp[10],j;
    for(i=0;i<size;i++)
        temp[i]=pro[a[i]];
    for(i=0;i<(size-1);i++){
        for(j=(i+1);j<size;j++){
            if(temp[j]<temp[i]){
                temp[i]=temp[i]+temp[j];
                temp[j]=temp[i]-temp[j];
                temp[i]=temp[i]+temp[j];
                a[i]=a[i]+a[j];
                a[j]=a[i]-a[j];
                a[i]=a[i]-a[j];
            }
        }
    }
}

void des_sort(int a[],int size){
    int temp[10],j;
    for(i=0;i<size;i++)
        temp[i]=pro[a[i]];
    for(i=0;i<(size-1);i++){
        for(j=(i+1);j<size;j++){
            if(temp[j]>temp[i]){
                temp[i]=temp[i]+temp[j];
                temp[j]=temp[i]-temp[j];
                temp[i]=temp[i]+temp[j];
                a[i]=a[i]+a[j];
                a[j]=a[i]-a[j];
                a[i]=a[i]-a[j];
            }
        }
    }
}

void fcfs(){
    int i,cur_p=initial_p;
    t_st=0;
    for(i=0;i<no_s;i++){
        t_st+=abs(cur_p-pro[i]);
        cur_p = pro[i];
        printf("\nP%d  %d",i+1,pro[i]);
    }
    printf("\nseek time: %d\n",t_st);
}

void scan(){
    int u_part[10],l_part[10],u_flag=0,l_flag=0,curp=initial_p;
    t_st=0;
    for(i=0;i<no_s;i++){
        if(pro[i]<initial_p){
            l_part[l_flag]=i;
            l_flag++;
        }else{
            u_part[u_flag]=i;
            u_flag++;
        }
    }
    ase_sort(u_part,u_flag);
    des_sort(l_part,l_flag);
    for(i=0;i<u_flag;i++){
        t_st+=abs(curp-pro[u_part[i]]);
        curp=pro[u_part[i]];
    }
    t_st+=abs(199-curp);
    curp=199;
    for(i=0;i<l_flag;i++){
        t_st+=abs(curp-pro[l_part[i]]);
        curp=pro[u_part[i]];
    }
    printf("\nSeek time: %d\n",t_st);
}

void cscan(){
    int u_part[10],l_part[10],u_flag=0,l_flag=0,curp=initial_p;
    t_st=0;
    for(i=0;i<no_s;i++){
        if(pro[i]<initial_p){
            l_part[l_flag]=i;
            l_flag++;
        }else{
            u_part[u_flag]=i;
            u_flag++;
        }
    }
    ase_sort(u_part,u_flag);
    ase_sort(l_part,l_flag);
    for(i=0;i<u_flag;i++){
        t_st+=abs(curp-pro[u_part[i]]);
        curp=pro[u_part[i]];
    }
    t_st+=abs(199-curp);
    curp=0;
    for(i=0;i<l_flag;i++){
        t_st+=abs(curp-pro[l_part[i]]);
        curp=pro[u_part[i]];
    }
    printf("\nSeek time: %d\n",t_st);
}

void main(){
    int choice;
    printf("\nEnter no of seek: ");
    scanf("%d",&no_s);
    printf("\nInitial position:");
    scanf("%d",&initial_p);
    printf("positions (LIMIT=199): ");
    for(i=0;i<no_s;i++){
        scanf("%d",&pro[i]);
    }
    printf("MENU\n1. FCFS\n2. SCAN\n3. CSCAN\n4. Exit\nChoice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1: fcfs();
                break;
        case 2: scan();
                break;
        case 3: cscan();
                break;   
    }


}