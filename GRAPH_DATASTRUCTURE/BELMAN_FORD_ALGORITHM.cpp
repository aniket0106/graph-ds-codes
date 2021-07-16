#include<stdio.h>
#include<stdlib.h>
struct Queue
{
	int data;
	struct Queue *next;
};
struct Queue *front=NULL,*rear=NULL;
struct Queue* nn (int data)
{
	struct Queue *p=(struct Queue*)malloc(sizeof(struct Queue));
	p->data=data;
	p->next=NULL;
	return p;
}
void insert(int data)
{
	struct Queue *p=nn(data);
	if(!front)
	{
		front=rear=p;
		return;
	}
	rear->next=p;
	rear=p;
}
int deleteN()
{
	struct Queue *p=front;
	int data=p->data;
	front=front->next;
	free(p);
	p=NULL;
	return data;
}
void bellmanford (int g[][])
{
	int i=0,j=0;
	for(j=0;j<v-1;j++)
	{
		visited={0};
		visited[s]=1;
		for(i=0;i<e;i++)
		{
			if(g[i][0]==s && g[i][2]+d[s]<d[g[i][1]])
			{
				insert(i);
				visited[i]=1;
				d[g[i][1]]=d[s]+g[i][2];
			}
		}
	}
}
int main ()
{
	
}
