#include<stdio.h>
#include<stdlib.h>
//structure of tree
struct Tree
{
	int data;
	int height;
	struct Tree *left;
	struct Tree *right;
};
//root
struct Tree *root=NULL;
//creation of new node
struct Tree* nn (int data)
{
	struct Tree* p=(struct Tree*)malloc(sizeof(struct Tree));
	p->data=data;
	p->height=1;
	p->left=p->right=NULL;
	return p;
}
//inorder
void inorder (struct Tree* t)
{
	if(t)
	{
		inorder(t->left);
		printf("%d  ",t->data);
		inorder(t->right);
	}
}
//max height
int max(int x,int y)
{
	return x>y?x:y;
}
//height function
int height (struct Tree* t)
{
	if(t)
		return t->height;
	else
		return 0;
}
//get balance factor
int getbf(struct Tree* t)
{
	if(t)
		return height(t->left)-height(t->right);
	else
		return 0;
}
//ll rotation
struct Tree* llrotation (struct Tree* ptr)
{
	struct Tree* ptr1=ptr->left;
	struct Tree *ptr2=ptr1->right;
	
	ptr1->right=ptr;
	ptr->left=ptr2;
	
	ptr->height=1+max(height(ptr->right),height(ptr->left));
	ptr1->height=1+max(height(ptr1->left),height(ptr1->right));
	
	return ptr1;
}
//rr rotation
struct Tree* rrrotation (struct Tree* ptr)
{
	struct Tree *ptr1=ptr->right;
	struct Tree* ptr2=ptr1->left;
	
	ptr1->left=ptr;
	ptr->right=ptr2;
	
	ptr->height=1+max(height(ptr->left),height(ptr->right));
	ptr1->height=1+max(height(ptr1->left),height(ptr1->right));
	
	return ptr1;
}
//inorder succssorstruct Tree* inorderS (struct Tree* t)
struct Tree* inorderS (struct Tree* t)
{
	while(t->left)
		t=t->left;
	return t;
}
//inorder predecessor
struct Tree* inorderP (struct Tree* t)
{
	while(t->right)
		t=t->right;
	return t;
}
//insert
struct Tree* insert (struct Tree* ptr,int ele)
{
	int bf=0;
		if(!ptr)
			return nn(ele);
		else if(ptr->data < ele)
			ptr->right=insert(ptr->right,ele);
		else if(ptr->data > ele)
			ptr->left=insert(ptr->left,ele);
		else 
			return ptr;
		ptr->height=1+max(height(ptr->left),height(ptr->right));
		bf=getbf(ptr);
		if(bf<-1 && ptr->right->data<ele)
			return rrrotation(ptr);
		if(bf<-1 && ptr->right->data>ele)
		{
			ptr->right=llrotation(ptr->right);
			return rrrotation(ptr);
		}
		if(bf>1 && ptr->left->data>ele)
			return llrotation(ptr);
		if(bf>1 && ptr->left->data<ele)
		{
			ptr->left=rrrotation(ptr->left);
			return llrotation(ptr);
		}
		return ptr;
}
//delete
struct Tree* deleteN (struct Tree* ptr,int ele)
{
	struct Tree* ptr1;
	int bf;
	if(ptr)
	{
		if(ptr->data==ele && !ptr->left && !ptr->right)
		{
			if(root==ptr)
			{
				root=NULL;
				return NULL;
			}
			free(ptr);
			return NULL;
		}
		else if(ptr->data < ele)
			ptr->right=deleteN(ptr->right,ele);
		else if(ptr->data > ele)
			ptr->left=deleteN(ptr->left,ele);
		else
		{
			if(ptr->right)
			{
				ptr1=inorderS(ptr->right);
				ptr->data=ptr1->data;
				ptr->right=deleteN(ptr->right,ptr->data);
			}
			else
			{
				ptr1=inorderP(ptr->left);
				ptr->data=ptr1->data;
				ptr->left=deleteN(ptr->left,ptr->data);
			}
		}
		ptr->height=1+max(height(ptr->left),height(ptr->right));
		bf=getbf(ptr);
		if(bf<-1 && getbf(ptr->right)<=0)
			return rrrotation(ptr);
		if(bf<-1 && getbf(ptr->right)>0)
		{
			ptr->right=llrotation(ptr->right);
			return rrrotation(ptr);
		}
		if(bf>1 && getbf(ptr->left)>=0)
			return llrotation(ptr);
		if(bf>1 && getbf(ptr->left)<0)
		{
			ptr->right=rrrotation(ptr->right);
			return llrotation(ptr);
		}
		return ptr;
	}
	else 
		return NULL;
}
int main()
{
	root=insert(root,20);
	root=insert(root,40);
	root=insert(root,60);
	root=insert(root,50);
	root=insert(root,55);
	root=insert(root,52);
	root=deleteN(root,52);
	root=deleteN(root,50);
	inorder(root);
	printf("\n%d",root->data);
	
}
/*
//left rotation
struct Tree* leftrotate(struct Tree *ptr)
{
	struct Tree *ptr1=ptr->right;
	struct Tree *ptr2=ptr1->left;
	
	ptr1->left=ptr;
	ptr->right=ptr2;
	
	ptr->height=1+max(height(ptr->left),height(ptr->right));
	ptr1->height=1+max(height(ptr1->left),height(ptr1->right));
	return ptr1;
}
//right rotation
struct Tree* rightrotate (struct Tree *ptr)
{
	struct Tree *ptr1=ptr->left;
	struct Tree *ptr2=ptr1->right;
	
	ptr1->right=ptr;
	ptr->left=ptr2;
	
	ptr->height=1+max(height(ptr->left),height(ptr->right));
	ptr1->height=1+max(height(ptr1->left),height(ptr1->right));
	return ptr1;	
}
//create avl
struct Tree* insert(struct Tree *t,int ele)
{
	int bf=0;
	if(t==NULL)
		return nn(ele);
	else if(ele>t->data)
		t->right=insert(t->right,ele);
	else if(ele<t->data)
		t->left=insert(t->left,ele);
	else
		return t;
	t->height=1+max(height(t->left),height(t->right));
	bf=getbf(t);
	if(bf<-1 && t->right->data<ele)
		return leftrotate(t);
	if(bf<-1 && t->right->data>ele)
	{
		t->right=rightrotate(t->right);
		return leftrotate(t);
	}
	if(bf>1 && t->left->data>ele)
		return leftrotate(t);
	if(bf>1 && t->left->data<ele)
	{
		t->left=leftrotate(t->left);
	    return rightrotate(t);
	}
	return t;
}
*/
