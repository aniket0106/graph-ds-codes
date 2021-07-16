#include<stdio.h>
#include<stdlib.h>


int v=6,e=8;
void dijkstra (int source,int visited[],int g[8][3])
{
	int i=0,j=0,min=100,x,y;
	int d[v]={100,100,100,100,100,100};
	for(i=0;i<v;i++)
	{
		printf("%d   ",d[i]);
	}
	
	d[source]=0;
	visited[source]=1;
	for(j=0;j<v-1;j++)
	{
		for(i=0;i<e;i++)
		{
			if(g[i][0]==source && visited[g[i][1]]==0)
			{
				x=g[i][0];
				y=g[i][1];
				if(d[x]+g[i][2]<d[y])
					d[y]=d[x]+g[i][2];
			}
		}
		min=100;
		for(i=0;i<v;i++)
		{
			if(visited[i]!=1 && min>d[i])
			{
				min=d[i];
				source=i;
			}
		}
		visited[source]=1;
	}
	for(i=0;i<v;i++)
	{
		printf("%d   ",d[i]);
	}
}
int main()
{
	int i=0;
	int visited[6]={0};
int g[8][3]={
			{0,1,3},
			{0,2,6},
			{1,2,2},
			{1,3,8},
			{2,4,4},
			{3,5,2},
			{4,3,3},
			{4,5,6}
			};
	dijkstra(0,visited,g);
	return 0;
}
