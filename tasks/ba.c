#include<stdio.h>
int main()
{
	int r,p,alc[10][10],n,i,j,k,req[10][10],nm[10][10],ava[10],ind=0;
	printf("enter the number of process:");
	scanf("%d",&p);
	printf("enter the nummber of resources:");
	scanf("%d",&r);
	printf("enter the resource allocation of the graph:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&alc[i][j]);
		}
	}
	printf("enter the resource request allocation of the graph:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&req[i][j]);
		}
}
    int finish[10],safeseq[10],work[10],flag;
	printf("enter the need matrix of the graph:\n");
		for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			nm[i][j]=req[i][j]-alc[i][j];
			printf(" %d",nm[i][j]);
        }
        printf("\n");
}
    for(i=0;i<p;i++)
    {
    	work[i]=ava[i];
	}
	    for(i=0;i<p;i++)
    {
    	finish[i]=0;
	}
	for(k=0;k<p;k++)
	{
		for(i=0;i<p;i++)
		{
			if(finish[i]==0)
			{
				int flag=0;
				for(j=0;j<r;j++)
				{
					if(nm[i][j]>work[j])
					{
						flag=1;
						break;
					}
				}
				
			}
			if(flag==0)
			{
				safeseq[i]=i;
				for(j=0;j<r;j++)
				{
					work[j]+=alc[i][j];
					finish[i]=1;
				}
			}
		}
	}
	printf("\n following is the safe sequence");
	for(i=0;i<p;i++)
	{
		printf("P%d ",safeseq[i]);
	} 
}
