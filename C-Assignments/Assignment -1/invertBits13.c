#include <stdio.h>
#include <iostream>

using namespace std;

void fun(int arr[], int len, int pos)
{
    for (int i = pos; i <= len; i++) {
        if (arr[i] == 0)
            arr[i] = 1;
        else
            arr[i] = 0;
    }
    for (int i = 0; i <= len; i++)
        printf("%d", arr[i]);
    printf("\n");
}

int main() {
    int num, i=0, arr[20];
    //printf("enter number:\n");
    cin >> num;
    while (num!=0) {
        arr[i] = num % 2;
        num = num / 2;
        i++;
    }
    int pos;
    //printf("enter position:\n");
    cin >> pos;
    int br[20];
    for (int k = 0, j = i; k <= i; k++, j--) {
        br[k] = arr[j];
    }
    fun(br, i, pos);
    return 0;
}