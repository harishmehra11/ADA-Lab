#include<stdio.h>
#include<time.h>


 int gcd(int a,int b)
  {
     if(b==0)
     return a;
     return gcd(b,a%b);
  }
  


 void main()
 {
 clock_t start,end;
 int a,b,result;
 printf("Enter the first number: ");
 scanf("%d",&a);
 printf("Enter the second number: ");
 scanf("%d",&b);
 start=clock();
 result=gcd(a,b);
 end=clock();
 printf("The greatest common divisor: %d \nTime taken :%f \n",result,(double)(end-start)/CLOCKS_PER_SEC);
 
 }

