#include<stdio.h>
#include<stdlib.h>
#define c 100
int v=4;
void floydwarshall (int g[4][4])
{
	int i=0,j=0,k=0;
	for(k=0;k<v;k++)
	{
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			{
				if(i==j)
					continue;
				if((i==k)||(j==k))
					continue;
				if(g[i][j]>g[i][k]+g[k][j])
					g[i][j]=g[i][k]+g[k][j];
			}
		}
	}
	for(i=0;i<v;i++)
	{
		printf("\n");
		for(j=0;j<v;j++)
		{
			printf("%d   ",g[i][j]);
		}
	}
}
int main ()
{
	int g[][4]={
				{0,5,c,10},
				{c,0,3,c},
				{c,c,0,1},
				{c,c,c,0}
				};
	floydwarshall(g);
}
