#include<stdio.h>
#include<stdlib.h>
struct stack
{
	struct Tree *data;
	struct stack *next;
};
struct stack *top=NULL;
struct stack* ne (struct Tree *data)
{
	struct stack *ptr=(struct stack*)malloc(sizeof(struct stack));
	ptr->data=data;
	ptr->next=NULL;
	return ptr;
}
void push(struct Tree *data)
{
	struct stack *ptr=ne(data);
	if(!top)
		top=ptr;
	else
	{
		ptr->next=top;
		top=ptr;
	}
}
struct Tree* pop ()
{
	struct Tree *data=top->data;
	struct stack *ptr=top;
	top=top->next;
	free(ptr);
	ptr=NULL;
	return data;
}
struct Queue
{
	struct Tree *data;
	struct Queue *next=NULL;
};
struct Queue *front=NULL,*rear=NULL;
struct Queue* nn (struct Tree *data)
{
	struct Queue *p=(struct Queue*)malloc(sizeof(struct Queue));
	p->data=data;
	p->next=NULL;
	return p;
}
void insert(struct Tree *data)
{
	struct Queue *ptr=nn(data);
	if(!front)
		front=rear=ptr;
	else
	{
		rear->next=ptr;
		rear=ptr;
	}
}
struct Tree* deleteN ()
{
	struct Queue *ptr=front;
	struct Tree *data=front->data;
	front=front->next;
	free(ptr);
	ptr=NULL;
	return data;
}
struct Tree
{
	int data;
	struct Tree *left;
	struct Tree *right;
};
struct Tree *root=NULL;

struct Tree* nn1 (int data)
{
	struct Tree *p=(struct Tree*)malloc(sizeof(struct Tree));
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void preorder (struct Tree *root)
{
	if(root)
	{
		printf("%d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder (struct Tree *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d",root->data);
	}
}
void inorder (struct Tree *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}
void levelorder (struct Tree *root)
{
	
}
void preorder1 (struct Tree *root)
{
	while(root || top)
	{
		if(root)
		{
			push(root);
			printf("%d   ",root->data);
			root=root->left;
		}
		else
			root=pop()->right;
	}
}
void inorder1 (struct Tree *root)
{
	while(root || top)
	{
		if(root)
		{
			push(root);
			root=root->left;
		}
		else
		{
			root=pop();
			printf("%d   ",root->data);
			root=root->right;
		}
	}
}
int sum (struct Tree *root)
{
	if(root)
		return root->data+sum(root->left)+sum(root->right);
	else
		return 0;
}
int count (struct Tree *root)
{
	if(!root)
		return 0;
	else 
		return 1+count(root->left)+count(root->right);
}
int count_deg0 (struct Tree *root)
{
	if(!root)
		return 0;
	else if(!root->left && !root->right)
		return 1;
	else 
		return count_deg0(root->left) + count_deg0(root->right);   
}
int count_deg1 (struct Tree *root)
{
	if(!root || !root->left && !root->right)
		return 0;
	if(!root->left && root->right)
		return 1+count_deg1(root->right);
	else if(root->left && !root->right)
		return 1+count_deg1(root->left);
	else 
    	return count_deg1(root->left)+count_deg1(root->right);
}
int count_deg2 (struct Tree *root)
{
	if(!root || !root->left && !root->right)
		return 0;
	else if(root->left && root->right)
		return 1+count_deg2(root->left)+count_deg2(root->right);
	else if(root->left)
		count_deg2(root->left);
	else 
		count_deg2(root->right);

	
}
int max (int a, int b)
{
	return a>b?a:b;
}
int height (struct Tree *root)
{
	if(root)
		return 1+max(height(root->left),height(root->right));
	else
		return 0;
}
void createTree ()
{
	int data=-1;
	struct Tree *ptr=NULL,*ptr1=NULL;
	printf("enter the data");
	scanf("%d",&data);
	ptr=nn1(data);
	root=ptr;
	insert(root);
	while(front)
	{
		ptr=deleteN();
		printf("\n enter the left chiild");
		scanf("%d",&data);
		if(data!=-1)
		{
			ptr1=nn1(data);
			ptr->left=ptr1;
			insert(ptr1);
		}
		printf("\n enter the right chiild");
		scanf("%d",&data);
		if(data!=-1)
		{
			ptr1=nn1(data);
			ptr->right=ptr1;
			insert(ptr1);
		}
	}
}


int main()
{
	int ch=0;
	createTree();
	while(1)
	{
		printf("\n 1. preorder");
		printf("\n 2. inorder");
		printf("\n 3. postorder");
		printf("\n 4. count the number of node with degree 0");
		printf("\n 5. count the number of node with degree 1");
		printf("\n 6. count the number of node with degree 2");
		printf("\n 7. count the number of node");
		printf("\n 8. height of tree");
		printf("\n 9. sum of all nodes");
		printf("\n 10. exit");
		printf("\n enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:preorder(root);
			break;
			case 2:inorder(root);
			break;
			case 3:postorder(root);
			break;
			case 4:printf("%d",count_deg0(root));
			break;
			case 5:printf("%d",count_deg1(root));
			break;
			case 6:printf("%d",count_deg2(root));
			break;
			case 7:printf("%d",count(root));
			break;
			case 8:printf("%d",height(root));
			break;
			case 9:printf("%d",sum(root));
			break;
			case 10:exit(0);
			break;
			default:printf("\n invalid input");
			break;
		}	
	}
}
