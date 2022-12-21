#include<stdio.h> 
int main() 
{ 
 int p,r,i,j,k,y,alloc[20][20],max[20][20],avail[50],ind =0; 
 printf("enter the no of process:"); 
 scanf("%d",&p); 
 printf("enter the no of resources"); 
 scanf("%d",&r); 
 for(i=0;i<p;i++) 
 { 
 for(j=0;j<r;j++) 
 scanf("%d",&alloc[i][j]); 
 } 
 printf("enter teh max matrix"); 
 for(i=0;i<p;i++) 
 { 
 for(j=0;j<r;j++) 
 scanf("%d",&max[i][j]); 
 } 
 printf("enter the available matrix"); 
 for(i=0;i<r;i++) 
 scanf("%d",&avail[i]); 
 int finish[p],safesequence[p],work[r],need[p][r]; 
 for(i=0;i<r;i++) 
 { 
 work[i]=avail[i]; 
 } 
 for(i=0;i<p;i++) 
 { 
 finish[i]=0; 
 } 
 //calculationg need matrix 
 for(i=0;i<p;i++) 
 { 
 for(j=0;j<r;j++) 
 need[i][j]=max[i][j]-alloc[i][j]; 
 } 
 printf("need matrix is"); 
 for(i=0;i<p;i++) 
 { 
 printf("\n"); 
 for(j=0;j<r;j++) 
 printf("%d",need[i][j]); 
 } 
 for(i=0;i<r;i++) 
 { 
 work[i]=avail[i]; 
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
 if(need[i][j]>work[j]) 
 { 
 flag=1; 
 break; 
 } 
 } 
 if(flag==0) 
 { 
 safesequence[ind ++]=i; 
 for(y=0;y<r;y++) 
 work[y]+=alloc[i][y]; 
 finish[i]=1; 
 } 
 } 
 } 
 } 
 printf("\n follwing is the safe sequence"); 
 for(i=0;i<p;i++) 
 printf("p%d",safesequence[i]); 
 } 
