#include<stdio.h> 
void main()
{
int ms,ps,nop,np,rempages,i,j,x,y,pa,offset; 
int s[10],fno[10][20];
printf("\n enter the memory size.."); 
scanf("%d",&ms);
printf("\n enter the page size.."); 
scanf("%d",&ps);
nop=ms/ps;
printf("\n the no.of pages available in memory are...%d",nop); 
printf("\n enter number of processes...");
scanf("%d",&np); 
rempages=nop; 
for(i=1;i<=np;i++)
{
printf("\n enter no.of pages required for p[%d]...",i); 
scanf("%d",&s[i]);
if(s[i]>rempages)
{
printf("\n memory is full"); 
break;
}
rempages=rempages-s[i];
printf("\n enter the pagetable for p[%d]...",i); 
for(j=0;j<s[i];j++)
scanf("%d",&fno[i][j]);
}
printf("\n enter logical address to find physical address"); 
printf("\n enter process number and pagenumber and offset..."); 
scanf("%d%d%d",&x,&y,&offset); 
if(x>np||y>=s[i]||offset>=ps)
printf("\n invalid process or page number or offset"); 
else
{
pa=fno[x][y]*ps+offset;
printf("\n the physical address is...%d",pa);
}    
}

