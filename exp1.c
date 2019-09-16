#include<stdio.h>
//#include<process.h>
//#include<conio.h>

void fcfs(int n, int *b_time,int *w_time,int *t_time){
	int i,temp=0;
	for(i=0;i<n;i++){
		t_time[i]=0; w_time[i]=0;
		temp=temp+ b_time[i];
		t_time[i] = temp;
		w_time[i] = temp - b_time[i];
	}
}

void sjf(int n, int *b_time,int *w_time,int *t_time){
	int temp=0,order[10]={0,1,2,3,4,5,6,7,8,9},i=0,j=0;
   //	bt=&b_time; wt=&w_time; tt=&t_time;
	for(i=0;i<(n-1);i++){
		for(j=(i+1);j<n;j++){
			if(b_time[order[i]]>b_time[order[j]]){
				order[i]=order[i]+order[j];
				order[j]=order[i]-order[j];
				order[i]=order[i]-order[j];
			}
		}
	}
	for(i=0;i<n;i++){
		temp+=b_time[order[i]];
		t_time[order[i]]=temp;
		w_time[order[i]]=t_time[order[i]]-b_time[order[i]];
	}
		printf("sjf sheduling: \n\nPro   BT   WT   TT");
	for(i=0;i<n;i++){
		printf("\nP%d    %d   %d   %d",(order[i]+1),b_time[order[i]],w_time[order[i]],t_time[order[i]]);
	}
}

void priority(int n, int *b_time,int *w_time,int *t_time){
	int temp=0,p[10],i,j,order[10]={0,1,2,3,4,5,6,7,8,9};
   //	bt=b_time; wt=w_time; tt=t_time;
	printf("\nprocess priority : ");
	for(i=0;i<n;i++)
	{
		printf("P%d ",i+1);
		scanf("%d",&p[i]);
	}
	for(i=0;i<(n-1);i++)
	{
		for(j=i;j<n;j++)
		{
			if(p[order[i]]>p[order[j]])
			{
				order[i]=order[i]+order[j];
				order[j]=order[i]-order[j];
				order[i]=order[i]-order[j];
			}
		}
	}
	for(i=0;i<n;i++){
		temp+=b_time[order[i]];
		t_time[order[i]]=temp;
		w_time[order[i]]=temp-b_time[order[i]];
	}
	printf("\nPriority Sheduling: \n");
	printf("\nPro   P   BT   WT   TT");
	for(i=0;i<n;i++){
		printf("\nP%d   %d   %d   %d   %d",(i+1),p[order[i]],b_time[order[i]],w_time[order[i]],t_time[order[i]]);
	}
}

void rr(int n, int *b_time,int *w_time,int *t_time){
	int ts,i,j,nr,temp=0,rt[10],flag=0;
   //	bt=b_time; wt=w_time; tt=t_time;
	nr=n;
	printf("\nenter the time slice \n");
	scanf("%d",&ts);
	for(i=0;i<n;i++)
	{
		rt[i]=b_time[i];
	}
	while(nr>0)
	{
		if(rt[flag]>=0)
		{
			if(rt[flag]<=ts)
			{
				temp+=rt[flag];
				t_time[flag]=temp;
				w_time[flag]=t_time[flag]-b_time[flag];
				nr=nr-1;
				rt[flag]=0;

			}
			else
			{
				temp=temp+ts;
				rt[flag]-=ts;
			}
		}
		if(flag==n-1)
		{
			flag=0;
		}
		else
		{
			flag++;
		}
	}
	printf("\nRound Robin :\n");
	printf("\nPR   BT   WT   TT");
	for(i=0;i<n;i++)
	{
		printf("\n%d   %d   %d   %d",i+1,b_time[i],w_time[i],t_time[i]);
	}
}

void main(){
	int n,i,choice, b_time[10], w_time[10], t_time[10];
	float avg_tt=0, avg_wt=0;
	//clrscr();
	printf("enter the no of process: ");
	scanf("%d",&n);
	printf("\nEnter BT of process: ");
	for(i=0;i<n;i++){
		printf("\n%d : ", (i+1));
		scanf("%d",&b_time[i]);
	}
	printf("\nMENU\n1. FCFS\n2. SJF \n3. Priority \n4. RR \n5. Exit\nEnter your choice: ");
	scanf("%d", &choice);
	switch(choice){
		case 1: fcfs(n,b_time,w_time,t_time);
				break;
		case 2: sjf(n,b_time,w_time,t_time);
				break;
		case 3: priority(n,b_time,w_time,t_time);
				break;
		case 4: rr(n,b_time,w_time,t_time);
				break;
		//default: exit(0);
	}
	if(choice==1){
		printf("\nProcess Info \n");
		printf("process  BT    WT    TT\n");
		for(i=0;i<n;i++){
			avg_tt= avg_tt + t_time[i];
			avg_wt= avg_wt + w_time[i];
			printf("%d        %d     %d     %d\n",(i+1),b_time[i],w_time[i],t_time[i]);
		}
	}
	else {
		for(i=0;i<n;i++){
			avg_tt= avg_tt + t_time[i];
			avg_wt= avg_wt + w_time[i];
		}
	}
	avg_wt= avg_wt/n;
	avg_tt= avg_tt/n;
	printf("\navg      %f     %f\n", avg_wt, avg_tt);
}
