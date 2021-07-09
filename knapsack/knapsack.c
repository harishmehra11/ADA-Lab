
#include <stdio.h>
#include<time.h>
#include<stdlib.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int K[n + 1][W + 1];


	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1]
						+ K[i - 1][w - wt[i - 1]],
						K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[n][W];
}


int main()
{
	clock_t start,end;
	int objects;
	printf("Enter the number of objects: ");
	scanf("%d",&objects);
	int val[objects];
	int wt[objects] ;
	printf("Enter the value array:");
	for(int i=0;i<objects;i++)
	scanf("%d",&val[i]);
	printf("Enter the weight array:");
	for(int i=0;i<objects;i++)
	scanf("%d",&wt[i]);
	
	int W ;
	printf("Enter the capacity:");
	scanf("%d",&W);
	
	int n = sizeof(val) / sizeof(val[0]);
	start=clock();
	printf("%d", knapSack(W, wt, val, n));
	end=clock();
	printf("\nTime taken:%f\n",(double)(end-start)/CLOCKS_PER_SEC);
	return 0;
}

