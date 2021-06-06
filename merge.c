	#include<stdio.h>
	#include<stdlib.h>
	#include<time.h>

	void merge(int arr[],int l,int mid,int h)
	{
	   int n1=mid-l+1;
	   int n2=h-mid;
	   
	   int arrL[n1];
	   int arrR[n2];
	   
	   for(int i=0;i<n1;i++)
	   {
	      arrL[i]=arr[l+i];
	   }
	  
	   for(int i=0;i<n2;i++)
	   {
	      arrR[i]=arr[mid+1+i];
	   }
	   
	   int i=0;
	   int j=0;
	   int k=l;
	   
	   while(i<n1 && j<n2)
	   {
	       if(arrL[i]<=arrR[j])
	       {
		  arr[k]=arrL[i];
		  i++;
		  k++;     
	       
	       }
	       else
	       {
	 	  arr[k]=arrR[j];
	 	  k++;
	 	  j++;      
	       }
	   }
	   
	   while(i<n1)
	   {
	     arr[k]=arrL[i];
		  i++;
		  k++;   
	   
	   }
	   
	   while(j<n2)
	   {   
	       arr[k]=arrR[j];
	 	  k++;
	 	  j++;  
	   }
	}
	
	
	


	void mergeSort(int arr[],int l,int h)
	{
	   if(l<h)
	   { 
	     int mid=l+(h-l)/2;
	     mergeSort(arr,l,mid);
	     mergeSort(arr,mid+1,h);
	     merge(arr,l,mid,h);
	   }
	}


	void printArray(int array[],int n)
	{
	    for(int i=0;i<n;i++)
	    {
	    	printf("%d ",array[i]);
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
	      mergeSort(array,0,n-1);
	      end=clock();
	      printf("\nSorted Array:\n");
	       printArray(array,n);
	       printf("\nTime taken=%f\n",(double)(end-start)/CLOCKS_PER_SEC);
	       return 0;
	}
