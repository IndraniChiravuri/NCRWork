#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void swap(int &x, int &y) {
    x = x + y;
    y = x - y;
    x = x - y;
}

void selectionSort(int ar[], int n) {
    int pos;
    for(int i = 0; i < n - 1; i ++) {
        pos = i;
        for(int j = i + 1; j < n; j ++) {
            if(ar[pos] > ar[j])
                pos = j;
        }
        if(pos != i) {
            swap(ar[i], ar[pos]);
        }
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
    selectionSort(ar,n);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
    cout << endl;
}