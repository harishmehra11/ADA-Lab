#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insertionSort(int array[],int n)
{
 for(int i=1;i<n;i++)
   {
   	int temp=array[i];
   	int j=i-1;
   	while(j>-1&&temp<array[j])
			{
				array[j+1]=array[j];
				j--;
			}
   	
   	array[j+1]=temp;
   }

}

void printArray(int array[],int n)
{
    for(int i=0;i<n;i++)
    {
    	printf("%d\t",array[i]);
    	}
}

int main()
{
    clock_t start,end;
    int n;
    printf("Enter the size:");
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;i++)
    {
    	array[i]=rand()%100;
    }
    printArray(array,n);
    start=clock();
      insertionSort(array,n);
      end=clock();
      printf("\nSorted Array:\n");
       printArray(array,n);
       printf("\nTime taken=%f\n",(double)(end-start)/CLOCKS_PER_SEC);
       return 0;
}
