#include<stdio.h>
#include<stdlib.h>
#define v 7
struct Queue
{
	int data;
	struct Queue *next;
};
struct Queue *front=NULL,*rear=NULL;
struct Queue* nn(int data)
{
	struct Queue *p=(struct Queue*)malloc(sizeof(struct Queue));
	p->data=data;
	p->next=NULL;
	return p;
}
void insert(int ele)
{
	struct Queue* p=nn(ele);
	if(front==NULL)
	{
		front=rear=p;
		return;
	}
	rear->next=p;
	rear=p;
}
int deleteN()
{
	int data=front->data;
	struct Queue *ptr=front;
	front=front->next;
	free(ptr);
	ptr=NULL;
	return data;
}
void bfs(int startV,int visited[],int g[v][v])
{
	int data,i;
	printf("\n%d",startV);
	visited[startV]=1;
	insert(startV);
	while(front)
	{
		data=deleteN();
		for(i=0;i<v;i++)
		{
			if(g[data][i]==1&&visited[i]==0)
			{
				printf("\n%d",i);
				visited[i]=1;
				insert(i);
			}	
		}
	}
}
int main()
{
	int g[7][7]={
		       {0,1,1,1,0,0,0},
		       {1,0,1,0,0,0,0},
		       {1,1,0,1,1,0,0},
		       {1,0,1,0,1,0,0},
		       {0,0,1,1,0,1,1},
		       {0,0,0,0,1,0,0},
		       {0,0,0,0,1,0,0}
	          };
    int visited[7]={0};
    bfs(0,visited,g);
}
