#include <limits.h>
#include <stdio.h>
#include<stdbool.h>


#define V 5


int minDistance(int dist[], bool sptSet[])
{
	
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

int printSolution(int dist[], int n)
{
int sum=0;
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; i++)
	{
		printf("%d = %d\n", i+1, dist[i]);
		sum+=dist[i];
		}
		
		printf(" Total weight=%d\n",sum);
}


void dijkstra(int graph[V][V], int src)
{
	int dist[V]; 

	bool sptSet[V]; 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;


	dist[src] = 0;

	
	for (int count = 0; count < V - 1; count++) {
		
		int u = minDistance(dist, sptSet);

		
		sptSet[u] = true;

		for (int v = 0; v < V; v++)

			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	
	printSolution(dist, V);
}


int main()
{
	
	int graph[V][V] = { { 0, 10, 0, 30,100},
						{ 10, 0, 50, 0, 0 },
						{ 0, 50, 0, 20, 10},
						{ 30, 0, 20, 0, 60},
						{ 100, 0, 10, 60,0},
						};
						
	int start;
     printf("Starting point?");
     scanf("%d",&start);
	dijkstra(graph, start-1);

	return 0;
}

