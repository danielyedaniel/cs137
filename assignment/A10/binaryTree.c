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
	return getDepth(t->root);
}


int main(void)
{
	//public test order matters
	struct bst *tree = bst_create();
	bst_insert(100, tree);
	bst_insert(150, tree);
	bst_insert(78, tree);
	bst_insert(88, tree);
	assert(bst_min(tree) == 78);
	assert(bst_max(tree) == 150);
	bst_print(tree);
	bst_insert(-130, tree);
	assert(tree->count == 5);
	bst_insert(-130, tree);
	assert(tree->count == 5);
	bst_print(tree);
	assert(bst_search(tree, 100));
	assert(!bst_search(tree, 90));
	assert(bst_height(tree) == 2);
	bst_print(tree);
// continue with secret tests.. order matters
	bst_insert(120, tree);
	bst_insert(113, tree);
	bst_insert(-60, tree);
	bst_insert(90, tree);
	bst_insert(190, tree);
	bst_print(tree);
	assert(bst_min(tree) == -130);
	assert(bst_max(tree) == 190);
	assert(tree->count == 10);
	assert(bst_height(tree) == 3);
 	bst_destroy(tree);
	struct bst *tr = bst_create();
	bst_insert(100, tr);
	bst_insert(90, tr);
	bst_insert(80, tr);
	assert(bst_min(tr) == 80);
	assert(bst_max(tr) == 100);
	assert(tr->count == 3);
	bst_print(tr);
	assert(bst_height(tr) == 2);
	bst_destroy(tr);
	struct bst *tr2 = bst_create();
	bst_insert(100, tr2);
	bst_insert(190, tr2);
	bst_insert(280, tr2);
	bst_insert(300, tr2);
	bst_insert(490, tr2);
	bst_insert(580, tr2);
	assert(bst_min(tr2) == 100);
	assert(bst_max(tr2) == 580);
	assert(tr2->count == 6);
	assert(bst_height(tr) == 5);
	bst_print(tr2);
	bst_destroy(tr2);
	struct bst *tr3 = bst_create();
	bst_insert(100, tr3);
	assert(bst_min(tr3) == 100);
	assert(bst_max(tr3) == 100);
	assert(tr3->count == 1);
	assert(bst_height(tr3) == 0);
	bst_print(tr3);
	bst_destroy(tr3);

}

