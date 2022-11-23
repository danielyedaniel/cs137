#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

void printsorted(char* word, int len){
    int *a=calloc(26,sizeof(int));
    char *b=calloc(26,sizeof(char));
    for(int i=0;i<len;i++){
        if(word[i]-97>=0 && word[i]-97<=25){
            a[word[i]-97]+=1;
        }
    }
    b[0]=97;
    for(int i=1;i<26;i++){
        b[i]=i+97;
        int temp=a[i];
        char p=b[i];
        int count=i-1;
        while(count>=0 && temp>a[count]){
            b[count+1]=b[count];
            a[count+1]=a[count];
            count--;
        }
        b[count+1]=p;
        a[count+1]=temp;
    }
    for(int i=0;i<26;i++){
        for(int x=0;x<a[i];x++){
            printf("%c",b[i]);
        }
    }
    printf("\n");
    free(a);
    free(b);
}
