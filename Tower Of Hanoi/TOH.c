#include <stdio.h>
#include<time.h>
  

void towerOfHanoi(int n, char src_rod, char des_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\n Disk 1 from rod %c to rod %c", src_rod, des_rod);
        return;
    }
    towerOfHanoi(n-1, src_rod, aux_rod, des_rod);
    printf("\n Disk %d from rod %c to rod %c", n, src_rod, des_rod);
    towerOfHanoi(n-1, aux_rod, des_rod, src_rod);
}
  
int main()
{
	int n;
	clock_t start,end;
	printf("Enter the number of disks:");
	scanf("%d",&n);
	start=clock();
	towerOfHanoi(n, 'A', 'C', 'B');  
    	end=clock();
    	printf("\nTime taken:%f \n",(double)(end-start)/CLOCKS_PER_SEC);
    	return 0;
}
