#include<stdio.h> 
void main()
{
int p[20],bt[20],wt[20],tat[20],i,j,n,temp; float wtavg=0,tatavg=0;
printf("\n enter the number of process.	");
scanf("%d",&n); for(i=0;i<n;i++)
{
p[i]=i;
printf("enter the burst time for process %d.	",i);
scanf("%d",&bt[i]);
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(bt[i]>bt[j])
{
temp=bt[i]; bt[i]=bt[j]; bt[j]=temp; temp=p[i]; p[i]=p[j]; p[j]=temp;
}
}
} wt[0]=0;
tat[0]=bt[0]; for(i=1;i<=n;i++)
{
wt[i]=wt[i-1]+bt[i-1];
tat[i]=tat[i-1]+bt[i];
}
for(i=0;i<n;i++)
{
wtavg=wtavg+wt[i]; tatavg=tatavg+tat[i];
}
printf("\n PROCESS\t BURST TIME\t WAITING TIME\t TURN AROUND TIME\n");
for(i=0;i<n;i++)
printf("\n p %d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]); printf("\n avg waiting time	%f",wtavg/n);

printf("\n avg turn around time.	%f",tatavg/n);
}
