#include<stdio.h> 
#include<math.h> 
int n,p=0,c=0,x=1; 
int buffer[50]; 
void producer() 
{ 
 if(p==n) 
 { 
 printf("\nWarning : Buffer is full"); 
 printf("\nCannot produce an item"); 
 } 
 if(p!=n) 
 { 
 printf("\nProducing an item, cannot consume"); 
 buffer[p]=x++; 
 printf("\nProduced an item"); 
 display(); 
 p++; 
 //printf("\np : %d",p); 
 } 
} 
void consumer() 
{ 
 if(p==0) 
 { 
 printf("\nWarning : Buffer is empty"); 
 printf("\nCannot consume an item"); 
 } 
 else if(c!=n) 
 { 
 printf("\nconsuming an item, cannot produce"); 
 int temp = buffer[--p]; 
 buffer[p]=0; 
 printf("\nConsumed an item : %d",temp); 
 //printf("\np : %d",p); 
 display(); 
 } 
 else 
 { 
 printf("\nWarning : Buffer is empty"); 
 printf("\nCannot consume an item"); 
 } 
} 
void display() 
{ 
 int i; 
 for( i=0;i<n;i++) 
 { 
 printf("\nbuffer[%d] : %d",i,buffer[i]); 
 } 
} 
int main() 
{ 
 int ch; 
 printf("Enter the size of the buffer : "); 
 scanf("%d",&n); 
 printf("\n1.Producer\n2.Consumer\n3.Exit"); 
 while(1) 
 { 
 printf("\n\nEnter your choice : "); 
 scanf("%d",&ch); 
 switch(ch) 
 { 
 case 1 : producer(); 
 break; 
 case 2 : consumer(); 
 break; 
 case 3 : exit(0); 
 default : printf("please enter a valid choice\n"); 
 } 
 } 
 return 0; 
}
