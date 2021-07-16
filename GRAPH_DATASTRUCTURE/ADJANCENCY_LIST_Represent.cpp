#include<stdio.h>
#include<stdlib.h>
#define v 7
struct Graph
{
	int data;
	struct Graph *next;
};
struct Graph *arr[v];
struct Graph* nn (int data)
{
	struct Graph *p=(struct Graph*)malloc(sizeof(struct Graph));
    p->data=data;
    p->next=NULL;
    return p;
}
void adjacencyList()
{
	int i,j,data,n;
	struct Graph *ptr,*ptr1;
	for(i=0;i<v;i++)
	{
		printf("\nenter the number of adjacent vertex for the vertex %d:\n",i);
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			printf("\nenter the %d adjacent vertex",j);
			scanf("%d",&data);
			ptr=nn(data);
			if(arr[i]==NULL)
		    {
		    	arr[i]=ptr;
			}
			else
			{
				ptr1=arr[i];
				while(ptr->next)
					ptr1=ptr1->next;
				ptr1->next=ptr;
			}
		}
	}
	for(i=0;i<v;i++)
	{
		printf("\nadjacent vertex for vertex %d",i);
		ptr=arr[i];
		while(ptr)
		{
			printf("%d-->",ptr->data);
			ptr=ptr->next;
		}
	}
}
int main()
{
	adjacencyList();
	return 0;
}
