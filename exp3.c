#include<stdio.h>
#include<conio.h>

int t_a=10,t_b=10,t_c=10;

void main(){
   int i,flag=0,temp=0,n,av_a=t_a,av_b=t_b,av_c=t_c;
   int ar[10],br[10],cr[10],a[10],b[10],c[10],done[]={0,0,0,0,0,0,0,0,0,0};
   clrscr();
   printf("Enter the no of process : ");
   scanf("%d",&n);
   printf("\nAllocated resources: \n    A B C\n");
   for(i=0;i<n;i++){
      printf("P%d: ",i+1);
      scanf("%d",&a[i]);
      scanf("%d",&b[i]);
      scanf("%d",&c[i]);
      av_a-=a[i]; av_b-=b[i]; av_c-=c[i];
   }
   printf("Enter required pro: \n    A B C\n");
   for(i=0;i<n;i++){
      printf("P%d: ",i+1);
      scanf("%d",&ar[i]);
      scanf("%d",&br[i]);
      scanf("%d",&cr[i]);
   }
   if(av_a<=0 || av_b<=0 || av_c<=0){
      printf("overflow!");
   }else{
      printf("alloc   reqr    avai    added\n");
      printf("A B C   A B C   A B C   A B C ");
      while(flag==0){
         for(i=0;i<n;i++){
            if(done[i]==0){
               if(ar[i]<=av_a && br[i]<=av_b && cr[i]<=av_c){
            	  //printf("\n%d %d %d  %d %d %d  %d %d %d  ",a[i],b[i],c[i],ar[i],br[i],cr[i],av_a[i],av_b[i],av_c[i]);
                  done[i]=1;
                  av_a+=a[i];
                  av_b+=b[i];
                  av_c+=c[i];
                  printf("%d",av_a[i]);
                  goto abc;
	       }
            }
         }
         if(i==n){
            for(i=0;i<n;i++)
            	temp+=done[i];
            if(temp==n)
            	printf("No Deadlock");
            else
            	printf("Deadlock!!");
            flag=1;
	 }
         abc:
      }
   }
   getch();
}
