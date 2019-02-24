#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void heapify(int ar[], int n, int i) {
    int hi = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && ar[left] > ar[hi])
        hi = left;
    if (right < n && ar[right] > ar[hi])
        hi = right;
    if (hi != i) {
        swap(ar[i], ar[hi]);
        heapify(ar,n,hi);
    }
}

void heapSort(int ar[], int n) {
    for (int i = n/2-1; i >= 0; i--)
        heapify(ar,n,i);
    for (int i = n-1; i >= 0; i--) {
        swap(ar[0],ar[i]);
        heapify(ar,i,0);
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
    heapSort(ar,n);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
    cout << endl;
}