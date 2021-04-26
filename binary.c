

#include <stdio.h>
  

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
       
        if (arr[mid] == x)
            return mid;
  
       
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
       
        return binarySearch(arr, mid + 1, r, x);
    }
    
   return -1;
}
  
int main(void)
{

     int size;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    int num;
    printf("Enter the number to be searched:\n");
    scanf("%d",&num);
    int n = sizeof(arr) / sizeof(arr[0]);
   
    int result = binarySearch(arr, 0, n - 1, num);
    (result == -1) ? printf("Element is not present in array. \n")
                   : printf("Element is present at index %d \n",
                            result);
    return 0;
}
