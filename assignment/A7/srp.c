#include <stdio.h>
#include <assert.h>
#include <string.h>

int shortestRepeatingPrefix(char s[]){
    for(int i=1;i<strlen(s);i++){
        if(strlen(s)%i==0){
            int sho=1;
            for(int x=1;x<=strlen(s)/i-1;x++){
                for(int j=0;j<i;j++){
                    if(s[j]!=s[x*i+j]){
                        sho=0;
                        break;
                    }
                }
                if(!sho)break;
            }
            if(sho)return i;
        }
    }
    return strlen(s);
}