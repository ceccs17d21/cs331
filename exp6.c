#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

// each philosopher takes 5 sec for eating | rest of the time for thinking
// N=4 means total 4 Philosophers & 4 spoons
#define N 4
#define EAT_TIME 3

int spn_sema[N] = {0,0,0,0};
int phil[N] = {0,1,2,3};
//int phil_stat[N] = {0,0,0,0};  // 0 --> Thinking  1 --> Eating 
int cmpt_flag = N;

void wait(int spoon){
    while(spn_sema[spoon] == 1);
    spn_sema[spoon] = 1;
}

void signal(int spoon){
    spn_sema[spoon] = 0;
}

void* eat(void* p){
    int* i = p;
    wait(*i);
    wait((*i+(N-1)) % N);

    //phil_stat[*i] = 1;
    printf("\nPhil %d Started eating!",(*i));
    sleep(EAT_TIME);
    printf("\nPhil %d Finished eating",(*i));
    //phil_stat[*i] = 0;
    
    signal(*i);
    signal((*i+(N-1)) % N);
    cmpt_flag--;
    return NULL;
}

void main(){
    int order[20],n_or,i;
    pthread_t thread_sp[20];
    for(i=0;i<N;i++)
        printf("\n%d. Phil_%d",i,i);
    printf("\nEnter the no of eat cycles: ");
    scanf("%d",&n_or);
    for(i=0;i<n_or;i++){
        scanf("%d",&order[i]);
    }
    for(i=0;i<n_or;i++){
        pthread_create(&thread_sp[i],NULL,eat,&phil[order[i]]);
    }
    while(cmpt_flag!=0);
}