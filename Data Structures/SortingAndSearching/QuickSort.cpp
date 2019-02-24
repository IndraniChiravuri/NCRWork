#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void swap(int &x, int &y) {
    x = x + y;
    y = x - y;
    x = x - y;
}

int partition(int ar[], int lo, int hi) {
    int pivot = ar[lo];
    int i = lo + 1;
    for (int j = lo+1; j <= hi; j++) {
        if (ar[j] < pivot) {
            if (i != j)
                swap(ar[i], ar[j]);
            i++;
        }
    }
    ar[lo] = ar[i-1];
    ar[i-1] = pivot;
    return i-1;
}

void quickSort(int ar[], int lo, int hi) {
    if (lo < hi) {
        int m = partition(ar,lo,hi);
        quickSort(ar,lo,m-1);
        quickSort(ar,m+1,hi);
    }
}

int main() {
    int n;
    cout << "Array Size: ";
    cin >> n;
    int ar[n];
    cout << "Array Elements: ";
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    quickSort(ar,0,n-1);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
    cout << endl;
}