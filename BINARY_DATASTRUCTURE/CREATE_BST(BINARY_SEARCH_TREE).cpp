#include<stdio.h>
#include<stdlib.h>
//stack structure
struct Stack
{
	struct Tree *data;
	struct Stack *next;
};
//top of the stack
struct Stack *top=NULL;
//creating the node
struct Stack* Snn(struct Tree* data)
{
	struct Stack* p=(struct Stack*)malloc(sizeof(struct Stack));
	p->data=data;
	p->next=NULL;
	return p;	
} 
//inserting into stack
void push (struct Tree* data)
{
	struct Stack* p=Snn(data);
	if(top==NULL)
		top=p;
	else
	{
		p->next=top;
		top=p;
	}
}
//deleting node from stack
struct Tree* pop ()
{
	struct Tree* data;
	struct Stack* ptr;
	ptr=top;
	data=top->data;
	top=top->next;
	free(ptr);
	ptr=NULL;
	return data;
}
struct Tree
{
	int data;
	struct Tree* left;
	struct Tree* right;
};
struct Tree *root=NULL;
struct Tree* nn(int data)
{
	struct Tree *p=(struct Tree*)malloc(sizeof(struct Tree));
	p->data=data;
	p->left=p->right=NULL;
	return p;
}
//inorder predessor of a given node
struct Tree* inorderP (struct Tree* t)
{
	while(t->right)
		t=t->right;
	return t;
}
//inorder successor of a given node
struct Tree* inorderS (struct Tree* t)
{
	while(t->left)
		t=t->left;
	return t;
}
//max out of two
int max(int x,int y)
{
	return x>y?x:y;
}
//height of tree
int height(struct Tree *h)
{
	if(h)
	{
		return 1+max(height(h->left),height(h->right));
	}
	else 
		return 0;
}
//inorder traversal recursive
void inorder(struct Tree *t)
{
	while(top || t)
	{
		if(t)
		{
			push(t);
			t=t->left;
		}
		else
		{
			t=pop();
			printf("%d  ",t->data);
			t=t->right;
		}
	}
}
struct Tree* createBst(struct Tree* t,int ele)
{
	struct Tree* r=NULL;
	
	if(!t)
	{
		t=nn(ele);
		return t;
	}
	else
	{
		while(t)
		{
			if(t->data==ele)
				break;
			r=t;
			if(t->data>ele)
				t=t->left;
			else if(t->data<ele)
				t=t->right;
		}
		if(r->data>ele)
			r->left=nn(ele);
		else
			r->right=nn(ele);
		return r;
	}
	return NULL;
} 
//deletion from tree
struct Tree* deleteN(struct Tree* ptr,int ele)
{
	struct Tree* ptr1=NULL;
	if(ptr)
	{
		if(ptr->data && !ptr->left && !ptr->right)
		{
			if(root==ptr)
			{
				root=NULL;
				return root;
			}
			free(ptr);
			return NULL;
		}
		else if(ptr->data > ele)
			ptr->left=deleteN(ptr->left,ele);
		else if(ptr->data < ele)
			ptr->right=deleteN(ptr->right,ele);
		else
		{
			if(height(ptr->left)>height(ptr->right))
			{
				ptr1=inorderP(ptr->left);
				ptr->data=ptr1->data;
				ptr->left=deleteN(ptr->left,ptr1->data);
			}
			else
			{
				ptr1=inorderS(ptr->right);
				ptr->data=ptr1->data;
				ptr->right=deleteN(ptr->right,ptr1->data);
			}
			return ptr;
		}
	}
	return NULL;
}
int main()
{
	root=createBst(root,60);
	createBst(root,50);
	createBst(root,70);
	createBst(root,45);
	createBst(root,55);
	createBst(root,70);
	createBst(root,85);
	inorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	deleteN(root,60);
	deleteN(root,50);
	deleteN(root,85);
	inorder(root);
	return 0;
}
