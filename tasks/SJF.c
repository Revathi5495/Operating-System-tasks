//shortest job first
#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	printf("enter no.of processes:");
	scanf("%d",&n);
	int a[20],arrtime[n],burtime[n],comptime[n],tat[n],wt[n],i,gn=0,c,k,t,j,ex[n],min;
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
			if(burtime[j]>=burtime[j+1])
			{
				t=burtime[j];
				burtime[j]=burtime[j+1];
				burtime[j+1]=t;
				t=arrtime[j];
				arrtime[j]=arrtime[j+1];
				arrtime[j+1]=t;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		ex[i]=0;
	}
	min=arrtime[0];
	for(i=0;i<n;i++)
	{
		if(min>arrtime[i])
		min=arrtime[i];
	}
	if(min==0)
	{
	   for(i=0;i<n;i++)
	   {
	   	if(arrtime[i]==0)
	   	{
	   		gn=gn+burtime[i];
	   		ex[i]=1;
	   		comptime[i]=gn;
	   	    tat[i]=comptime[i]-arrtime[i];
	      	wt[i]=tat[i]-burtime[i];
		   }
	   }
	}
	else
	{
		gn=min;
		for(i=0;i<n;i++)
		{
			if(arrtime[i]==min)
			{
				gn=gn+burtime[i];
				ex[i]=1;
				comptime[i]=gn;
	   	        tat[i]=comptime[i]-arrtime[i];
	        	wt[i]=tat[i]-burtime[i];
			}
		}	
	}
	for(i=0;i<n;i++)
	{
		if(ex[i]==1)
		continue;
		gn=gn+burtime[i];
		comptime[i]=gn;
	   	tat[i]=comptime[i]-arrtime[i];
	   	wt[i]=tat[i]-burtime[i];
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
	printf("average waiting time:%d",sum/n);
	printf("average turn around time:%d",sum1/n);
	
}
