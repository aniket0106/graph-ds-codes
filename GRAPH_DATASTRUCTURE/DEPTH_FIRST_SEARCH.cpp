#include<stdio.h>
#include<stdlib.h>
int g[7][7]={
			{0,1,1,1,0,0,0},
			{1,0,1,0,0,0,0},
			{1,1,1,0,0,0,0},
			{1,0,1,0,1,0,0},
			{0,0,1,1,0,1,1},
			{0,0,0,0,1,0,0},
			{0,0,0,0,1,0,0}
			};
int visited[7]={0};
struct stack
{
	int data;
	struct stack *next;
};
struct stack *top=NULL;
struct stack* nn (int data)
{
	struct stack* p=(struct stack*)malloc(sizeof(struct stack));
	p->data=data;
	p->next=NULL;
	return p;
}
void push(int ele)
{
	struct stack *p=nn(ele);
	if(top==NULL)
		top=p;
	else
	{
		p->next=top;
		top=p;
	}
}
int peek()
{
	if(top)
		return top->data;
}
void pop ()
{
	struct stack *p=top;
	int data=top->data;
	top=top->next;
	free(p);
	p=NULL;
}
int unvisited (int x)
{
	int i=0;
	for(i=0;i<7;i++)
	{
		if(g[x][i]==1 && visited[i]==0)
			return i;
	}
	return -1;
}
void dfs (int startV)
{
	int x;
	printf("%d  ",startV);
	visited[startV]=1;
	if(unvisited(startV)!=-1)
	{
		push(startV);
	}
	while(top)
	{
		if((x=unvisited(peek()))!=-1)
		{
			printf("%d  ",x);
			visited[x]=1;
			if(unvisited(x)!=-1)
				push(x);
		}
		else
			pop();
	}
	printf("end");
}
int main()
{
	dfs(0);
	return 0;
}
