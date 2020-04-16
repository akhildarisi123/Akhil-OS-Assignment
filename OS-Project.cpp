#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
int main() 
{ 
  int count,i,j,m=0,n,y=0;
  int time,remain=0,min,flag=0; 
  int wait_time=0,turn_a_time=0,a_time[10],b_time[10],p[10],z[10];
  float k=0,x=0; 
  printf("NOTE: ");
  printf("\n   1. Arrival time should be greater than 2 as CPU remains idle for first 3 secs.\n");
  printf("   2. Burst time should be less tha 10\n");
  printf("\nEnter number of Process: "); 
  scanf("%d",&n); 
  for(count=0;count<n;count++) 
  { 
    printf("\nEnter Arrival Time and Burst Time for Process  %d :",count+1); 
    scanf("%d",&a_time[count]); 
    scanf("%d",&b_time[count]);  
  } 
for(i=0;i<n;i++)
{
	if(a_time[i]==0)
	{
		printf("\nINVALID ARRIVAL TIME\n");
		getch();
		exit(1);
	}
}
for(i=0;i<n;i++)
{
	if(a_time[i]<3)
	{
		printf("\nINVALID Arrival Time it should be greater than 3\n");
		getch();
		exit(1);
	}
}
  printf("\n\nProcess\t\tTurnaround Time\t\tWaiting Time\n"); 
  printf("--------------------------------------------------------\n");
for(i=0;i<n;i++)
{
	m=m+b_time[i];
}
min=m;
time=m;
for(i=0;i<n;i++)
{
	if(a_time[i]<time)
	{
		time=a_time[i];
	}
}
for(i=time;i<=m;i=i+b_time[j])
{
	min=m;
	remain=0;
	flag=0;

	for(count=0;count<n;count++)
	{
	
		if(a_time[count]<=i)
		{

			if(b_time[count]<min)
			{

				min = b_time[count];
				j=count;
				flag=1;
			}
			remain=1;	 
		}
	}
	if(flag==1&&remain==1)
	{
		wait_time=i-a_time[j];
		turn_a_time=wait_time+b_time[j];
		printf("P[%d]\t\t%d\t\t%d\n\n",j+1,turn_a_time,wait_time); 
		k=k+wait_time;
		x=x+turn_a_time;
		a_time[j]=m+1;
                        p[y]=j+1;
		z[y]=i;
		y++;
	}
}
printf("Average Waiting Time= %.2f\n\n",k/n); 
printf("Avg Turnaround Time = %.2f\n\n",x/n); 
printf("Total time taken by processor to complete all the jobs : %d\n\n",m);  
printf("Queue  for order of execution:\n");
printf("Process		");
for(i=0;i<n;i++)
{
	printf(" P[%d]   ",p[i]);
	if(i==(n-1))
	{
		printf("End");
	}
}
 return 0; 
}

