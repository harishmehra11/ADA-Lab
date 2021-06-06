#include<stdio.h>
#include<stdbool.h>
bool ltor =true;
bool rtol =false;



 int getPos(int array[],int n,int mob)
 {
    for(int i=0;i<n;i++)
    {
       if(array[i]==mob)
       return i+1;
    }
 }


 int getMob(int array[],bool direction[],int n)
 {
   int prev=0;
   int  mob=0;
   for(int i=0;i<n;i++)
   {
      if(direction[array[i]-1]==rtol&&i!=0)
      {
         if(array[i]>array[i-1]&& array[i]>prev )
         {
             mob=array[i];
             prev=mob;
         }
      }
      
        if(direction[array[i]-1]==ltor&&i!=n-1)
      {
         if(array[i]>array[i+1]&& array[i]>prev )
         {
             mob=array[i];
             prev=mob;
         }
      }
   }
   
   if(mob==0&&prev==0)
   return 0;
   else 
   return mob;
 }
 
 
 int fact(int n)
 {
   int res=1;
   for(int i=1;i<=n;i++)
   res*=i;
   return res;
 }
 
 void printPermutation(int array[],bool direction[],int n)
 {
    int mob=getMob(array,direction,n);
    int pos=getPos(array,n,mob);
    
       if (direction[array[pos - 1] - 1] ==  rtol)
       {
       int temp=array[pos-1];
       array[pos-1]= array[pos-2];
       array[pos-2]=temp;
       }
  
    else if (direction[array[pos - 1] - 1] == ltor)
    {
        int temp=array[pos];
       array[pos]= array[pos-1];
       array[pos-1]=temp;
    }
      
  
    
    for (int i = 0; i < n; i++)
    {
        if (array[i] > mob)
        {
            if (direction[array[i] - 1] == ltor)
                direction[array[i] - 1] = rtol;
            else if (direction[array[i] - 1] == rtol)
                direction[array[i] - 1] = ltor;
        }
    }
  
    for (int i = 0; i < n; i++)
    printf("%d",array[i]);
    printf("\n");
 }
void permutations(int n)
{
   int array[n];
   bool direction[n];
   for(int i=0;i<n;i++)
   {
   	array[i]=i+1;
   	printf("%d",array[i]);
   }
   printf("\n");
   
   for(int i=0;i<n;i++)
   {
        direction[i]=rtol; 
   }
   
   for(int i=1;i<fact(n);i++)
   {
   	printPermutation(array,direction,n);
   }
}
  
int main()
{
   int n;
   printf("Enter the number:");
   scanf("%d",&n);
   permutations(n);
   return 0;
   
}

