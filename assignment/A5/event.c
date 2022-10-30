#include "event.h"
#include <stdio.h>
#include <assert.h>

int convertTod(struct tod a){
    int b=60*a.hour+a.minute;
    return b;
}

struct tod convertEvent(struct event a){
    int start=convertTod(a.start);
    int end=convertTod(a.end);
    struct tod b={start,end};
    return b;
}

int freetime (struct event schedule[], int n, int hour, int min){
    int a=hour*60+min;

    for(int i=0;i<n;i++){
        struct tod num=convertEvent(schedule[i]);
        if(a>=num.hour && a<num.minute)return 0;
    }
    return 1;
    
}
