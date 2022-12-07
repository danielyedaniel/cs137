#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef struct dlnode{
	int data;
	struct dlnode *next;
	struct dlnode *prev;

} dlnode;

typedef struct {
	dlnode *head;	//points to the first element otherwise NULL
	dlnode *tail;	//points to the last element otherwise NULL
	int len;	// number of elements
} ndlst;

void dlistPrint(ndlst *lst)
{
	dlnode *node = lst->head;
	// iterate over the nodes (items) until node is NULL 
	// and print the data
	for (; node; node = node->next)
		printf("%d  ", node->data);
	printf("\n");
}

void dlistPrintReverse(ndlst *lst)
{
	dlnode *node = lst->tail;
	// iterate over the nodes (items) until node is NULL 
	// and print the data
	for (; node; node = node->prev)
		printf("%d  ", node->data);
	printf("\n");
}
//Pre: None
//Post: Creates a null list
struct ndlst *dlistCreate(void)
{
	ndlst *ret = malloc(sizeof(ndlst));
	ret->head = NULL;
	ret->tail = NULL;
	ret->len = 0;
	return ret;
}

//Pre: lst is a valid list 
//Post: Destroys the list
void dlistDestroy(ndlst *lst)
{
	struct dlnode *next = NULL;
	struct dlnode *cur =  lst->head;
	while(cur!=NULL){
		next=cur->next;
		free(cur);
		cur=next;
	}
	free(lst);
}

//Pre: lst is valid
//Post: returns the number of elements in the list
int dlistLength(ndlst *lst)
{
	return lst->len;
}

//Pre: lst is a valid list with length of at least n>=1
//Post: nth item removed
void dlistRemoveElem(ndlst *lst, int n){
	struct dlnode *cur=lst->head;
	struct dlnode *prev=NULL;
	struct dlnode *post=NULL;
	for(int i=1;i<n;i++){
		cur=cur->next;
	}
	if(n>1){
		prev=cur->prev;
		if(n<lst->len){
			post=cur->next;
			prev->next=post;
			post->prev=prev;
		}else{
			prev->next=NULL;
			lst->tail=prev;
		}
	}else{
		if(n<lst->len){
			post=cur->next;
			post->prev=NULL;
			lst->head=post;
		}else{
			lst->head=NULL;
			lst->tail=NULL;
			lst->len=0;
		}
	}	
	free(cur);
	lst->len-=1;
}

// lst is a valid list
void dlistAddToFront(ndlst *lst, int elem)
{
	struct dlnode *e=malloc(sizeof(dlnode));
	e->data=elem;
	if(lst->len!=0){
		e->next=lst->head;
		lst->head->prev=e;
		e->prev=NULL;
		lst->head=e;
		if(lst->len==1)lst->tail=e->next;
	}else{
		lst->head=e;
		lst->tail=e;
		e->prev=NULL;
		e->next=NULL;
	}
	lst->len+=1;
}

// lst is a valid list
void dlistAddToEnd(ndlst *lst, int elem)
{
	struct dlnode *e=malloc(sizeof(dlnode));
	e->data=elem;
	if(lst->len!=0){
		e->prev=lst->tail;
		lst->tail->next=e;
		e->next=NULL;
		lst->tail=e;
		if(lst->len==1)lst->head=e->prev;
	}else{
		lst->tail=e;
		lst->head=e;
		e->prev=NULL;
		e->next=NULL;
	}
	lst->len+=1;
}

struct dlnode * swap(struct dlnode *item){
	struct dlnode *a=item->next;
	if(item->prev!=NULL)item->prev->next=a;
	if(a->next!=NULL)a->next->prev=item;
	item->next=a->next;
	a->next=item;
	a->prev=item->prev;
	item->prev=a;
	return a;
}
// lst is a valid list to be sorted in ascending order
void dlistSort(ndlst *lst)
{
	for(int i=0;i<lst->len;i++){
		struct dlnode *start=lst->head;
		bool swapMade=false;
		for(int j=0;j<lst->len-1;j++){
			if(start->data>start->next->data){
				if(j==0)lst->head=start->next;
				if(j==lst->len-2)lst->tail=start;
				swapMade=true;
				start=swap(start);
			}
			start=start->next;
		}
		if(!swapMade)break;
	}
}

// rotate the list n times to the left, assume, lst not empty
void dlistRotateLeft(ndlst *lst, int n)
{
	if(lst->len>1){
		int c=0;
		while(c<n){
			struct dlnode * h=lst->head;
			struct dlnode * e=lst->tail;
			lst->head=h->next;
			h->next->prev=NULL;
			lst->tail=h;
			e->next=h;
			h->prev=e;
			h->next=NULL;
			c++;
		}
	}
}

// rotate the list n times to the right, assume, lst not empty
void dlistRotateRight(ndlst *lst, int n)
{
	if(lst->len>1){
		int c=0;
		while(c<n){
			struct dlnode * h=lst->head;
			struct dlnode * e=lst->tail;
			lst->tail=e->prev;
			e->prev->next=NULL;
			lst->head=e;
			e->next=h;
			h->prev=e;
			e->prev=NULL;
			c++;
		}
	}
}

int main(void)
{
ndlst *lst1 = dlistCreate();
assert(dlistLength(lst1) == lst1->len);
assert(dlistLength(lst1) == 0);
dlistAddToEnd(lst1, 10);
dlistAddToFront(lst1, -20);
dlistAddToFront(lst1, 0);
dlistAddToEnd(lst1, 9);
dlistAddToFront(lst1, -9);
dlistAddToFront(lst1, 7);
dlistAddToEnd(lst1, 40);
assert(dlistLength(lst1) == lst1->len);
assert(dlistLength(lst1) == 7);
dlistPrint(lst1);
dlistPrintReverse(lst1);
dlistRemoveElem(lst1, 5);
dlistRemoveElem(lst1, 1);
dlistRemoveElem(lst1, 5);
dlistAddToEnd(lst1, 100);
assert(dlistLength(lst1) == lst1->len);
assert(dlistLength(lst1) == 5);
dlistPrint(lst1);
dlistPrintReverse(lst1);
dlistSort(lst1);
dlistPrint(lst1);
dlistRotateLeft(lst1, 2);
dlistPrint(lst1);
dlistRotateRight(lst1, 3);
dlistPrint(lst1);
dlistDestroy(lst1);
return 0;
}