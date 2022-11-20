#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
bool is_palindrome(char *s, int start, int finish){
    if(finish-start<1)return false;
    for(int i=0;i<finish-start;i++){
        if(s[start+i]!=s[finish-i])return false;
    }
    return true;
}
bool semicheck(char *s, int start){
    if(start==strlen(s))return true;
    for(int i=start+1;i<strlen(s);i++){
        if(s[i]==s[start]){
            if(is_palindrome(s,start,i) && semicheck(s,i+1))return true;
        }
    }
    return false;
}
bool is_semidrome(char *s){
    if(strlen(s)<2)return false;
    return semicheck(s, 0);
}

int main(void){
    char *c="eeleel";
    printf("%d",is_semidrome(c));
}