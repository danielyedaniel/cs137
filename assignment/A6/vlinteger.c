#include <stdio.h>
#include <assert.h>
#include "vlinteger.h"
#include <stdlib.h>
#include <stdbool.h>
struct linteger *vlintegerCreate(void) {
    struct linteger *t1 = malloc(sizeof(struct linteger));
    t1->arr = NULL;
    t1->length = 0;
    return t1;
}
void vlintegerDestroy(struct linteger *v){
    if(v){
        free(v->arr);
        free(v);
    }
    return;
}
void vlintegerRead(struct linteger *t1){
    int success;
    int count=0;       
    int hold;
    while(scanf("%d",&hold)==1){
        count++;
        t1->arr=(int*)realloc(t1->arr,sizeof(int)*count);
        t1->arr[count-1]=hold;
        t1->length=count;
    }
    return;
}
void vlintegerPrint(struct linteger *t1){
    printf("length=%d\n", t1->length);
    for(int i=0;i<t1->length;i++){
        printf("%d", t1->arr[i]);
    }
    printf("\n");
    return;
}
struct linteger * removeLeadingZero(struct linteger *t1){
    struct linteger *f=vlintegerCreate();
    int leading=0;
    int count=0;
    for(int i=0;i<t1->length;i++){
        if(t1->arr[i]!=0)break;
        count++;
    }
    int c=0;
    for(int i=count;i<t1->length;i++){
        f->length++;
        f->arr=realloc(f->arr,f->length*sizeof(int));
        f->arr[c]=t1->arr[i];
        c++;
    }
    vlintegerDestroy(t1);
    return f;
}
struct linteger * vlintegerAdder(struct linteger *t1, struct linteger *t2){
    struct linteger * lg;
    struct linteger * sm;
    if((t1->length)>=(t2->length)){
        lg=t1;sm=t2;
    }else{
        lg=t2;sm=t1;
    }
    struct linteger * final;
    int *result= malloc(lg->length*sizeof(int));
    bool remain=false;
    int res;
    int diff=lg->length-sm->length;
    for(int i=lg->length-1; i>=0;i--){if(i<diff){if(remain){res=lg->arr[i]+1;if(res==10){result[i]=0;}else{remain=false;result[i]=res;}}else{result[i]=lg->arr[i];}}else{res=lg->arr[i]+sm->arr[i-diff];if(remain)res++;if(res>9){remain=true;result[i]=res-10;}else{remain=false;result[i]=res;}}}if(remain){result=realloc(result, (lg->length+1)*sizeof(int));for(int i=lg->length;i>0;i--){result[i]=result[i-1];}result[0]=1;}final=vlintegerCreate();final->arr=result;final->length=lg->length + (remain ? 1 : 0);
    return final;
}
struct linteger * vlintegerMultDestroyer(struct linteger *t1, struct linteger *t2){
    struct linteger *final=vlintegerAdder(t1,t2);
    vlintegerDestroy(t1);
    return final;
}
struct linteger * vlintegerAdd(struct linteger *t1, struct linteger *t2){
    return removeLeadingZero(vlintegerAdder(t1,t2));
}
struct linteger * vlintegerMultHelp(int n, struct linteger *t1, int zero){
    struct linteger *final=vlintegerCreate();
    final->length=t1->length+1;
    final->arr=calloc((t1->length+1),sizeof(int));
    int res;
    for(int i=t1->length-1;i>=0;i--){
        res=n*t1->arr[i];
        res=res+final->arr[i+1];
        final->arr[i+1]=res%10;
        final->arr[i]=res/10;
    }

    final->length=t1->length+1+zero;
    final->arr=realloc(final->arr,(t1->length+1+zero)*sizeof(int));
    for(int i=1;i<=zero;i++){
        final->arr[final->length-i]=0;
    }
    return removeLeadingZero(final);
}
struct linteger * vlintegerMult(struct linteger *t1, struct linteger *t2){
    struct linteger * final=vlintegerCreate();
    final->length=t1->length+t2->length;
    final->arr=calloc((t1->length+t2->length),sizeof(int));
    int zeros=0;
    struct linteger * add;
    for(int i=t1->length-1;i>=0;i--){
        add=vlintegerMultHelp(t1->arr[i],t2,zeros);
        final=vlintegerMultDestroyer(final,add);
        zeros++;
        vlintegerDestroy(add);
    }
    final = removeLeadingZero(final);
    if(final->length==0){
        final->length=1;
        final->arr=calloc(1,4);
        return final;
    }
    return final;
}