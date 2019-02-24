#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void merge(int ar[], int lo, int m, int hi) {
    int i = lo, j = m + 1, k = 0;
    int temp[hi-lo+1];
    while (i <= m && j <= hi) {
        if (ar[i] <= ar[j])
            temp[k++] = ar[i++];
        else
            temp[k++] = ar[j++];
    }
    while (i <= m)
        temp[k++] = ar[i++];
    while (j <= hi)
        temp[k++] = ar[j++];
    for (i = lo; i <= hi; i++)
        ar[i] = temp[i-lo];
}

void mergeSort(int ar[], int lo, int hi) {
    if (lo == hi) return;
    int m = (int) (lo + ((hi-lo)/2));
    mergeSort(ar,lo,m);
    mergeSort(ar,m+1,hi);
    merge(ar,lo,m, hi);
}

int main() {
    int n;
    cout << "Array Size: ";
    cin >> n;
    int ar[n];
    cout << "Array Elements: ";
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    mergeSort(ar,0,n-1);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
    cout << endl;
}