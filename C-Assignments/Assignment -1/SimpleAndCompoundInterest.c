#include <cstdio>
#include <cmath>



#include <stdio.h>
#include<stdlib.h>
#include<math.h>

void simple_interest(int p,int n,float r) {
float si=(float)n*(float)p*r;
printf("Simple intrest:%f\n",si);
}
void compound_interest(float a,int p) {
    float ci;
    ci=a-(float)p;
    printf("Compunt interest:%f\n",ci);
}
void compound_amount(int p,int n,float r) {
    int t;
    float a;
    printf("Enter for many times a year interest to be calculated:\n");
    scanf("%d",&t);
    switch(t) {
        case 1:
            a=(float)p*pow((1+(r/1)),(float)n);
            printf("Calculated anually:%f",a);
            compound_interest(a,p);
            break;
       case 2:
            a=(float)p*pow((1+(r/2)),(2*(float)n));
            printf("calculated half yearly:%f\n",a);
            compound_interest(a,p);
            break;
       case 4:
            a=(float)p*pow((1+(r/4)),(4*(float)n));
            printf("calculated quarter yearly:%f\n",a);
            compound_interest(a,p);
            break;
       case 12:
            a=(float)p*pow((1+(r/12)),(12*(float)n));
            printf("calculated monthly:%f\n",a);
            compound_interest(a,p);
            break;
       case 365:
            a=(float)p*pow((1+(r/365)),(365*(float)n));
            printf("calculated dialy:%f\n",a);
            compound_interest(a,p);
            break;
       default:
            break;
    }
}
int main() {
    int p,n,si;
    float r;
    printf("Enter principle amount:\n years:\n rate:\n");
    scanf("%d %d %f",&p,&n,&r);
    simple_interest(p,n,r);
    compound_amount(p,n,r);
    return 0;
}