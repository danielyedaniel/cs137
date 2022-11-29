#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

void reverseConcatenate (void *lhs, void *rhs){
    strcat((char *)rhs, *(char **)lhs);
}

void concatenate (void *lhs, void *rhs){
    char *t=calloc(1001, sizeof(char));
    char *r=(char *)rhs;
    char *l=*(char **)lhs;    
    for(int i=0;i<strlen(l)+strlen(r);i++){
        if(i<strlen(l)){
            t[i]=(char)(l)[i];
        }else{
            t[i]=(char)(r)[i-(int)strlen(l)];
        }
    }
    strcpy((char *)rhs,t);
    free(t);
    
}