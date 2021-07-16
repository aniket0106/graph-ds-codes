#include<stdio.h>
#include<stdlib.h>
int knapsack(int profit[],int weight[],int wt,int n)
{
	int t[n+1][wt+1];
	int i=0,j=0;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=wt;j++)
		{
			if(i==0 || j==0)
				t[i][j]=0;
			if(weight[i]<=j)
				t[i][j]=t[i-1][j]>(t[i-1][j-weight[i]]+profit[i])?t[i-1][j]:(t[i-1][j-weight[i]]+profit[i]);
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=wt;j++)
		{
			printf("\n%d",t[i][j]);
		}
	}
	return t[n][wt];
}
int main()
{
	int res=0;
	int profit[4]={2,3,1,4};
	int weight[4]={3,4,6,5};
	printf("%d\n",knapsack(profit,weight,8,4));
	return 0;
}
