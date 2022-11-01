#include <stdio.h>
#include <assert.h>

typedef struct Point{
    int x;
    int y;
} point;

typedef struct Rectangle {
    point bottomLeft; // represents the bottom left corner of the rectangle
    int width;
    int height;
} rectangle;

rectangle intersection(rectangle rects[], int n){
    point low={rects[0].bottomLeft.x, rects[0].bottomLeft.y}, high={rects[0].bottomLeft.x+rects[0].width,rects[0].bottomLeft.y+rects[0].height};
    for(int i=1;i<n;i++){
        int btmlftx=rects[i].bottomLeft.x;
        int btmlfty=rects[i].bottomLeft.y;
        if(btmlftx>low.x)low.x=rects[i].bottomLeft.x;
        if(btmlfty>low.y)low.y=rects[i].bottomLeft.y;
        if(btmlftx+rects[i].width<high.x)high.x=btmlftx+rects[i].width;
        if(btmlfty+rects[i].height<high.y)high.y=btmlfty+rects[i].height;
    }
    rectangle zero = {{0,0},0,0};
    if(low.x>=high.x || low.y>=high.y)return zero;
    rectangle result = {{low.x,low.y}, high.x-low.x,high.y-low.y};
    return result;
}