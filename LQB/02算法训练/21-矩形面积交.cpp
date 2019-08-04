#include "stdio.h"
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
int main(){
    double x1,y1,x2,y2;    //矩形1
    double x3,y3,x4,y4;    //矩形2
    double m1,n1;        //交集左上角坐标.
    double m2,n2;        //交集右下角坐标.
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    scanf("%lf%lf%lf%lf",&x3,&y3,&x4,&y4);
    m1 = max(min(x1,x2),min(x3,x4));
    n1 = max(min(y1,y2),min(y3,y4));
    m2 = min(max(x1,x2),max(x3,x4));
    n2 = min(max(y1,y2),max(y3,y4));
    if(m2>m1 && n2>n1)
        printf("%.2f\n",(m2 - m1)*(n2 - n1));
    else
        printf("0.00\n");
    return 0;
}
