//first come first serve
#include<stdio.h>
int main()
{
	int n;
	printf("enter no.of processes:");
	scanf("%d",&n);
    int a[20],arrtime[n],burtime[n],comptime[n],tat[n],wt[n],i,gn=0,c,k,t,j;
	float sum=0,sum1=0;
	printf("enter arrival time and burst time of each process");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arrtime[i]);
		scanf("%d",&burtime[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(arrtime[j]>=arrtime[j+1])
			{
				t=arrtime[j];
				arrtime[j]=arrtime[j+1];
				arrtime[j+1]=t;
				t=burtime[j];
				burtime[j]=burtime[j+1];
				burtime[j+1]=t;
			}
		}
	}
	if(arrtime[0]==0)
	{
	   for(i=0;i<n;i++)
	   {
	   	gn=gn+burtime[i];
	   	comptime[i]=gn;
	   	tat[i]=comptime[i]-arrtime[i];
	   	wt[i]=tat[i]-burtime[i];
	   }
	}
	else
	{
		gn=arrtime[0];
		for(i=0;i<n;i++)
	   {
	   	gn=gn+burtime[i];
	   	comptime[i]=gn;
	   	tat[i]=comptime[i]-arrtime[i];
	   	wt[i]=tat[i]-burtime[i];
	   }
	}
	for(i=0;i<n;i++)
	{
		printf("%d %d %d %d %d\n",arrtime[i],burtime[i],comptime[i],wt[i],tat[i]);
	}
	for(i=0;i<n;i++)
	{
		sum=sum+wt[i];
		sum1=sum1+tat[i];
	}
	printf("average waiting time:%f",sum/n);
	printf("average turn around time:%f",sum1/n);
	
}
