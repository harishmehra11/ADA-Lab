	#include<stdio.h>
	#include<stdlib.h>
	#include<stdbool.h>
	#include<time.h>
	
	
	int partition(int arr[],int l,int h)
	{  
	   int pivot=arr[l];
	   int beg=l-1;
	   int end=h+1;
	   while(1)
	   {
	     
	     do{
	     beg++;
	     }while(arr[beg]<pivot);
	     do{
	     end--;
	     }while(arr[end]>pivot);
	     
	     if(beg>=end)
	     return end;
	     
	     int temp=arr[beg];
	     arr[beg]=arr[end];
	     arr[end]=temp;
	    }
	}    
	
	void quickSort(int arr[],int l,int h)
	{   
	   if(l<h)
	   { 
	       int pivot=partition(arr,l,h);
	       quickSort(arr,l,pivot);
	       quickSort(arr,pivot+1,h);
	       
	   }

	}


	
	
	
	
	void main()
	{
	   int n;
	  clock_t start,end;
	  printf("Enter the size of the array:");
	  scanf("%d",&n);
	  int arr[n];
	  for(int i=0;i<n;i++)
	  {
	    arr[i]=rand()%100;
	  }
	   for(int i=0;i<n;i++)
	  {
	    printf("%d ",arr[i]);
	  }
	  printf("\n");
	  start=clock();
	  quickSort(arr,0,n-1);
	  end=clock();
	  printf("\nSorted Array\n");
	    for(int i=0;i<n;i++)
	  {
	    printf("%d ",arr[i]);
	  }
	  printf("\nTime taken:%f \n",(double)(end-start)/CLOCKS_PER_SEC);
	  
	  
	  

	  
	}
