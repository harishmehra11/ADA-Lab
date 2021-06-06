#include <stdio.h>
#include<time.h>
 
int main(){
	int n,indeg[10],flag[10],count=0;
	clock_t start,end;
 
	printf("No of vertices:\n");
	scanf("%d",&n);
	int a[n][n];
 
	printf("Adjacency matrix:\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d ",&a[i][j]);

 
	for(int i=0;i<n;i++){
        indeg[i]=0;
        flag[i]=0;
    }
 
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            indeg[i]=indeg[i]+a[j][i];
 
    printf("\nOrder :");
 
 	start=clock();
    while(count<n){
        for(int k=0;k<n;k++){
            if((indeg[k]==0) && (flag[k]==0)){
                printf("%d ",(k+1));
                flag [k]=1;
            }
 
            for(int i=0;i<n;i++){
                if(a[i][k]==1)
                    indeg[k]--;
            }
        }
 
        count++;
    }
    end=clock();
    printf("\nTime taken:%f\n",(double)(end-start)/CLOCKS_PER_SEC);
 
    return 0;
}
