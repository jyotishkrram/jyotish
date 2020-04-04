#include<stdio.h>
#include<conio.h>
struct process
{
 int processID;
 int burstTime;
 int arrivalTime;
 int priority;
 int waitTime;
};
int total_time,burst_time=0;
int total=-1,i=-1;

struct process queue[50],result[50],swap;
int process_create() 
{
 int n;
 printf("enter the number of process you want to enter:");
 scanf("%d",&n);
 return n;
}
void execute() 
{
 if(total>=0)
 {
 int wait,j;
 if(burst_time!=0 && queue[0].burstTime!=0)
 {
 queue[0].burstTime--;
 burst_time--;
 queue[0].priority++;
 queue[0].arrivalTime=total_time+1;
 total_time++;

 for(wait=1;wait<=total;wait++)
 {
 queue[wait].priority+=2;
 queue[wait].waitTime=++queue[wait].waitTime;
 }
 }

 if(queue[0].burstTime==0)
 {
 i++;
 result[i]=queue[0];
 for(wait=0;wait<total;wait++)
 {
 queue[wait]=queue[wait+1];
 }
 total--;
 }
 for(wait=0;wait<total;wait++)
 {
 for(j=0;j<total;j++)
 {
 if(queue[wait].priority<=queue[j].priority)
 {
 swap=queue[wait];
 queue[wait]=queue[j];
 queue[j]=swap;
 }
 }
 }
 if(queue[0].priority<=queue[1].priority && total>=1)
 {
 swap=queue[0];
 for(wait=0;wait<total;wait++)
 {
 queue[wait]=queue[wait+1];
 }
 queue[total]=swap;
 }
 }
}
int main()
{
 int l,j,n=process_create(),count=0;
 float avg_WaitTime=0;
 struct process pcreate[n];
 for(l=0;l<n;l++)
 {
 pcreate[l].processID=l+1;
 printf("\nEnter the arrival time of process[%d]: ",l+1);
 scanf("%d",&pcreate[l].arrivalTime);
 printf("\nEnter the burst time of process[%d]: ",l+1);
 scanf("%d",&pcreate[l].burstTime);
 pcreate[l].priority=0;
 pcreate[l].waitTime=0;
 burst_time=burst_time+pcreate[l].burstTime;
 }
 for(l=0;l<n;l++)
 {
 for(j=0;j<n;j++)
 {
 if(pcreate[l].arrivalTime<pcreate[j].arrivalTime)
 {
 swap=pcreate[l];
 pcreate[l]=pcreate[j];
 pcreate[j]=swap;
 }
 if(pcreate[l].arrivalTime==pcreate[j].arrivalTime)
 {
 if(pcreate[l].burstTime<=pcreate[j].burstTime)
 {
 swap=pcreate[l];
 pcreate[l]=pcreate[j];
 pcreate[j]=swap;
 }
 }
 }
}
 printf("values:\n(sorted according to arrival time)\n\n");
 printf(" process table \n\n");
 printf(" PROCESS_ID ARRIVAL_TIME SERVICE_TIME \n\n");
 for(l=0;l<n;l++)
 {
 printf(" \t%d \t %d \t \t%d \t \n\n",pcreate[l].processID,pcreate[l].arrivalTime,pcreate[l].burstTime );
 }
 total_time=pcreate[0].arrivalTime;
 for(j=pcreate[0].arrivalTime;j<=pcreate[n-1].arrivalTime;j++)
 {
 for(l=0;l<n;l++)
 {
 if(pcreate[l].arrivalTime==j && count!=n)
 {
 total++;
 queue[total]=pcreate[l];
 count++;
 }
 if(count==n)
 break;
 }
 execute();
 total_time++;
 while(burst_time!=0 && count==n)
 {
 execute();
 total_time++;
 }
 if(count==n)
 break;
 }
 printf("process in order of their completion:\n\n");
 printf(" execution table \n\n");
 printf(" PROCESS ID ARRIVAL TIME SERVICE TIME WAITING TIME\n");
 for(l=0;l<n;l++)
 {
 for(j=0;j<n;j++)
 {
 if(result[l].processID==pcreate[j].processID)
 {
 printf(" \t%d  \t %d \t\t %d \t %d\n\n",result[l].processID,pcreate[j].arrivalTime,pcreate[j].burstTime,result[l].waitTime);
 break;
 break;
 }
 }
 avg_WaitTime+=(result[l].waitTime);
 }
 printf("average waiting time: %f\n",avg_WaitTime/n);
} 
