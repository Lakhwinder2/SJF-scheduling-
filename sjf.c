#include<stdio.h>
int main()
{
int i,no,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,burst=0;
int btime[10],tem,j,arrival[10],wtime[10],ttime[10],ta=0,total=0;
float wavgtime=0,tavgtime=0,turnsum=0,waitsum=0;
printf("\nEnter the No. of processes :");
scanf("%d",&no);
 
for(i=0;i<no;i++)
{
printf("\tEnter the burst time of %d process :",i+1);
scanf(" %d",&btime[i]);
printf("\tEnter the arrival time of %d process :",i+1);
scanf(" %d",&arrival[i]);
}
 
/*Sorting According to Arrival Time*/
 
for(i=0;i<no;i++)
{
for(j=0;j<no;j++)
{
if(arrival[i]<arrival[j])
{
tem=p[j];
p[j]=p[i];
p[i]=tem;
tem=arrival[j];
arrival[j]=arrival[i];
arrival[i]=tem;
tem=btime[j];
btime[j]=btime[i];
btime[i]=tem;
}
}
}
 
/*Arranging the table according to Burst time,
Execution time and Arrival Time
Arrival time <= Execution time
*/
 
for(j=0;j<no;j++)
{
burst=burst+btime[j];
min=btime[k];
for(i=k;i<no;i++)
{
if (burst>=arrival[i] && btime[i]<min)
{
tem=p[k];
p[k]=p[i];
p[i]=tem;
tem=arrival[k];
arrival[k]=arrival[i];
arrival[i]=tem;
tem=btime[k];
btime[k]=btime[i];
btime[i]=tem;
}
}
k++;
}
wtime[0]=0;
for(i=1;i<no;i++)
{
total=total+btime[i-1];
wtime[i]=total-arrival[i];
waitsum=waitsum+wtime[i];
}
 
wavgtime=(waitsum/no);
for(i=0;i<no;i++)
{
ta=ta+btime[i];
ttime[i]=ta-arrival[i];
turnsum=turnsum+ttime[i];
}
 
tavgtime=(turnsum/no);
 
printf("************************");
printf("\n RESULT:-");
printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
for(i=0;i<no;i++)
{
printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i],btime[i],arrival[i],wtime[i],ttime[i]);
}
 
printf("\n\nAVERAGE WAITING TIME : %f",wavgtime);
printf("\nAVERAGE TURN AROUND TIME : %f",tavgtime);
return 0;
}
