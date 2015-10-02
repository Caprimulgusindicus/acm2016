#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
#define PI 3.1415926
int n;
double x1;
double x2,y2,x3,y3;
double AB;
int main(){
    while(scanf("%d",&n)!=EOF){
        scanf("%lf%lf",&x1,&y1);//A
        scanf("%lf%lf",&x2,&y2);//B
        scanf("%lf%lf",&x3,&y3);//C
        double AB=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        double AC=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
        double BC=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        double BC2=BC/2;
        double d=sqrt(AB*AB-BC2*BC2);
        double r=d*BC2/AB;
        double cos=acos(-(AB*AB+AC*AC-BC*BC)/(2*AB*AC));
        double sum=r*cos+d;
        printf("%.4lf",sum);
    }

return 0;
}
