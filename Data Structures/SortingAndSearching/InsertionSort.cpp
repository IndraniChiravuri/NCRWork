
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void insertionSort(int ar[], int n) {
    int num;
    int j;
    for(int i = 1; i < n; i++) {
        num = ar[i];
        for(j = i - 1; j >= 0 && num < ar[j]; j--) {
            ar[j+1] = ar[j];
        }
        ar[j+1] = num;
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
    insertionSort(ar,n);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
    cout << endl;
}