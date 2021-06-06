#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int minInd(int arr[],int a,int b)
{
  if(a==b)
  return a;
  int min=minInd(arr,a+1,b);
  if(arr[a]<arr[min])
  return a;
  else return min;
  
}
void Select(int arr[],int n,int ind)
{
   if(ind==n)
   return;
   int min=minInd(arr,ind,n-1);
   if(min!=ind)
   {
   	int temp=arr[min];
   	arr[min]=arr[ind];
   	arr[ind]=temp;
   }
   Select(arr,n,ind+1);
}

int main()
{

  int n;
  clock_t start,end;
  printf("Enter the size of the array:");
  scanf("%d",&n);
  int arr[n];
  for(int i=0;i<n;i++)
  {
    arr[i]=rand()%30;
  }
   for(int i=0;i<n;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  start=clock();
  Select(arr,n,0);
  end=clock();
    for(int i=0;i<n;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\nTime taken:%f ",(double)(end-start)/CLOCKS_PER_SEC);
  
  
  

  return 0;

}

