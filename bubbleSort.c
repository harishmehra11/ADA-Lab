#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
   int n;
   printf("Enter the size of the array:");
   scanf("%d",&n);
   int array[n];
   for(int i=0;i<n;i++)
   {
      array[i]=rand()%30;
   }
   
     for(int i=0;i<n;i++)
   {
     printf("%d ",array[i]);
   }
   printf("\n");
}
