#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct bstnode {
	int item;
	struct bstnode *left;
	struct bstnode *right;
};

struct bst {
	struct bstnode *root;
	int count;
};

struct bst *bst_create(void)
{
	struct bst *t = malloc(sizeof(struct bst));
	t->root = NULL;
	t->count = 0;
	return t;
}

void destroy(struct bstnode *node)
{
	if (node != NULL)
	{
		destroy(node->left);
		destroy(node->right);
		free(node);
	}
}

void bst_destroy(struct bst *t)
{
	destroy(t->root);
	free(t);
}

int search(struct bstnode *t,int val){
	if(val==t->item)return 1;
	if(val<t->item){
		if(t->left){
			return search(t->left,val);
		}else{
			return 0;
		}
	}else{
		if(t->right){
			return search(t->right,val);
		}else{
			return 0;
		}
	}
}

int bst_search(struct bst *t, int val)
{
	return search(t->root, val);
}


void insert(int num, struct bstnode *t){
	if(num>t->item){
		if(t->right){
			insert(num,t->right);
		}else{
			struct bstnode *a=malloc(sizeof(struct bstnode));
			a->item=num;
			a->left=NULL;
			a->right=NULL;
			t->right=a;
		}
	}else if(num<t->item){
		if(t->left){
			insert(num,t->left);
		}else{
			struct bstnode *a=malloc(sizeof(struct bstnode));
			a->item=num;
			a->left=NULL;
			a->right=NULL;
			t->left=a;
		}
	}
}

void bst_insert(int num, struct bst *t)
{	
	if(t->count==0){
		struct bstnode *a=malloc(sizeof(struct bstnode));
		a->item=num;
		a->left=NULL;
		a->right=NULL;
		t->root=a;
		t->count+=1;
	}else if(!search(t->root,num)){
		insert(num, t->root);
		t->count+=1;
	}
	
}

void print(struct bstnode *node)
{
	if (node)
	{
		print(node->left);
		printf("%d ", node->item);
		print(node->right);
	}
}

void bst_print(struct bst *t)
{
	if (t->root)
	{
		print(t->root);
		printf("\n");
	}
}


int min(struct bstnode * t){
	if(t->left==NULL)return t->item;
	return min(t->left);
}
int bst_min(struct bst *t)
{
	return min(t->root);
}

int max(struct bstnode * t){
	if(t->right==NULL)return t->item;
	return max(t->right);
}
int bst_max(struct bst *t)
{
	return max(t->root);
}

int getDepth(struct bstnode * t){
	if(t->left==NULL && t->right==NULL)return 0;
	int left=0,right=0;
	if(t->left!=NULL)left=1+getDepth(t->left);
	if(t->right!=NULL)right=1+getDepth(t->right);
	return right>left ? right:left;
}

int bst_height(struct bst *t)
{
	if(!t->root)return -1;
	return getDepth(t->root);
}
