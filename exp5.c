#include<stdio.h>
//---BUFFER_SIZE = 5----
// mutex=0 
int mutex=0,full=0,empty=5;

int wait(){
    while(mutex==1);
    mutex=1;
}

int signal(){
    mutex=0;
}

void producer(){
    wait();
    if(full<5){
        full++;
        empty--;
        printf("\nproduced");
    }
    else
        printf("Buffer is full!");    

    signal();
}
void consumer(){
    wait();
    if(empty<5){
        empty++;
        full--;
        printf("consumed");
    }
    else
        printf("Buffer is empty");

    signal();
}

void main(){
    int c=1;
    while(c==1 || c==2){
        printf("\nMENU\n1. producer\n2. consumer\n3. exit\n choice: ");
        scanf("%d",&c);
        switch(c){
            case 1: producer();
                    break;
            case 2: consumer();
                    break;
        }
    }   
}