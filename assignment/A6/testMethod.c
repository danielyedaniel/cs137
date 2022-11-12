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

struct linteger * vlintegerAdd(struct linteger *t1, struct linteger *t2){
    return removeLeadingZero(vlintegerAdder(t1,t2));
}


struct linteger * vlintegerMultDestroyer(struct linteger *t1, struct linteger *t2){
    struct linteger *final=vlintegerAdder(t1,t2);
    vlintegerDestroy(t1);
    return final;
}




struct linteger * vlintegerMult(struct linteger *t1, struct linteger *t2){
    struct linteger *final = vlintegerCreate();
    struct linteger *current = vlintegerCreate();
    struct linteger *memLeak;
    int remainder = 0;
    int product, digit, index;
    
    
    for(int i = t1->length-1; i >= 0; i--){

        current->length = t2->length;
        current->arr = malloc(t2->length*sizeof(int));
        index = 0;
        for(int j = t2->length-1; j >= 0; j--){
            product = t1->arr[i] * t2->arr[j] + remainder;

            remainder = product/10;
            digit = product % 10;

            current->arr[index] = digit;
            index++;
        }

        if (remainder) {
            current->arr = realloc(current->arr, (t2->length + 1) * sizeof(int));
            current->arr[t2->length] = remainder;
            current->length = t2->length+1;
        }

        int temp;
        for(int l = 0; l < current->length/2; l++){
            temp = current->arr[l];
            current->arr[l] = current->arr[current->length-l-1];
            current->arr[current->length-l-1] = temp;
        }

        // t1->length-1 - i
        current->arr = realloc(current->arr, (current->length+(t1->length-1-i))*sizeof(int));
        for(int k = 0; k < t1->length-1-i; k++){
            current->arr[(current->length)+k] = 0;
        }
        current->length += t1->length-1-i;

        printf("penis\n");
        vlintegerPrint(current);

        if (i == t1->length-1) {
            final = current;
        } else {
            memLeak = final;
            final = vlintegerAdd(final, current);
            vlintegerDestroy(memLeak);
        }

        
    }
    return final;
}


int main(void) {
    struct linteger *int1 = vlintegerCreate();
    printf("Enter the digits separated by a space: \n");
    vlintegerRead(int1);
    vlintegerPrint(int1);
    assert(int1->arr[0] !=0);
    char c;
    scanf("%c", &c);
    struct linteger *int2 = vlintegerCreate();
    printf("Enter the digits separated by a space: \n");
    vlintegerRead(int2);
    vlintegerPrint(int2);
    assert(int2->arr[0] !=0);
    scanf("%c", &c);
    struct linteger *add = vlintegerAdd(int1, int2);
    printf("addition\n");
    vlintegerPrint(add);
    assert(add->arr[0] !=0);
    scanf("%c", &c);
    struct linteger *mult = vlintegerMult(int1, int2);
    printf("multiplication\n");
    vlintegerPrint(mult);
    assert(mult->arr[0] !=0);
    vlintegerDestroy(int1);
    vlintegerDestroy(int2);
    vlintegerDestroy(add);
    vlintegerDestroy(mult);
}
