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

int main (void)
{
 struct event schedule[] = {{{9,45},{9,55}},{{13,0},
 {14,20}},{{15,20},{16,30}}, {{17,0}, {19, 0}}};


assert(freetime(schedule, 4, 9, 30));
assert(freetime(schedule, 4, 9, 57));
assert(!freetime(schedule, 4, 9, 50));
assert(!freetime(schedule, 4, 9, 45));
assert(freetime(schedule, 4, 9, 55));

assert(freetime(schedule, 4, 4, 0));
assert(freetime(schedule, 4, 9, 0));
assert(freetime(schedule, 4, 10, 0));
assert(freetime(schedule, 4, 23, 0));

assert(!freetime(schedule, 4, 13, 0));
assert(!freetime(schedule, 4, 13, 34));
assert(!freetime(schedule, 4, 14, 0));
assert(!freetime(schedule, 4, 14, 10));
assert(freetime(schedule, 4, 14, 20));
assert(freetime(schedule, 4, 14, 50));

assert(freetime(schedule, 4, 15, 0));
assert(!freetime(schedule, 4, 15, 20));
assert(!freetime(schedule, 4, 15, 21));
assert(!freetime(schedule, 4, 16, 0));
assert(!freetime(schedule, 4, 16, 29));
assert(freetime(schedule, 4, 16, 30));
assert(freetime(schedule, 4, 16, 40));

assert(!freetime(schedule, 4, 17, 0));
assert(!freetime(schedule, 4, 17, 30));
assert(!freetime(schedule, 4, 18, 0));
assert(!freetime(schedule, 4, 18, 40));
assert(freetime(schedule, 4, 19, 0));


 return 0;
 }