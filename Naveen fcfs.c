#include<stdio.h>
int main()
{
int at[10],bt[10],ct[10],tat[10],wt[10];
int n,i;
printf("enter no of processes");
scanf("%d",&n);
printf("enter arrival time");
for(i=0;i<n;i++)
{
scanf("%d",&at[i]);
}
printf("enter burst time");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
}
ct[0]=at[0]+bt[0];
for(i=1;i<n;i++)
{
ct[i]=ct[i-1]+bt[i];
}
for(i=0;i<n;i++)
{
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];
}
printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
