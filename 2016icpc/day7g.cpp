#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const double pi=3.141592654;
double a;

int main()
{
    while(~scanf("%lf",&a))
    {
        double r=sqrt(a/(4*pi));
        /*double tem=((a-pi*r*r)/(pi*r*r)*(a-pi*r*r)/(pi*r*r))-r*r;
        double h=sqrt(tem);
        double v=pi*a*h/6;*/
        double l=(a-pi*r*r)/(pi*r);
        double h=sqrt(l*l-r*r);
        double v=(1.0/3.0)*pi*r*r*h;
        printf("%.2f\n%.2f\n%.2f\n",v,h,r);
    }
}