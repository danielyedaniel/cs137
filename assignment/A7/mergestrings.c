#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char* merge (char* s1, char* s2){
    char * final=calloc((strlen(s1)+strlen(s2))+2,sizeof(char));
    for(int i=0;i<(strlen(s1)+strlen(s2));i++){
        final[i]='\0';
    }
    int one=0,two=0,count=0;
    bool first=true;
    bool a=true;
    while(one<strlen(s1) || two<strlen(s2)){
        if(one>=strlen(s1)){
            first=false;
            if(two<strlen(s2) && a){final[count++]=32;a=false;}
        }
        if(two>=strlen(s2)){
            first=true;
            if(one<strlen(s1) && a){final[count++]=32;a=false;}
        }
        if(first){
            if(s1[one]!=32){
                final[count]=s1[one];
            }else{
                first=false;
                final[count]=32;
            }
            one++;
            count++;
        }else{
            if(s2[two]!=32){
                final[count]=s2[two];
            }else{
                first=true;
                final[count]=32;
            }
            two++;
            count++;
        }
    }
    return final;
}

int main(void){
    char a[]="one three five seven";
    char b[]="two four six";
    char * p=merge(a,b);
    printf("%s",p);
    printf("%d",(int)strlen(p));
    free(p);
}