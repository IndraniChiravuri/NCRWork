#include<stdio.h>
#include <stdlib.h>

int grossSalary(int sal,int hrd,int da) {
    return sal + hrd + da;
}
int percentage(int a,int b) {
    return (b * a) / 100;
}

int main() {
    int sal,h,d;
    printf("Enter basic salary:");
    scanf("%d", &sal);
    if(sal >= 1 && sal <= 4000) {
    	h = percentage(sal,10);
    	d = percentage(sal,50);
    	printf("%d\n", grossSalary(sal,h,d));
    } 	else if(sal > 4000 && sal <= 8000) {
        h = percentage(sal,20);
        d = percentage(sal,60);
        printf("%d\n", grossSalary(sal,h,d));
    }    else if(sal > 8000 && sal <= 12000) {
    	h = percentage(sal,25);
    	d = percentage(sal,70);
    	printf("%d\n", grossSalary(sal,h,d));
    } else {
        h = percentage(sal,30);
        d = percentage(sal,80);
        printf("%d\n", grossSalary(sal,h,d));
    }
    return 0;
}
