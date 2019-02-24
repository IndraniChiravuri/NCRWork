#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int binarySearch(int ar[], int n, int key) {
    int lo = 0;
    int hi = n-1;
    while (lo <= hi) {
        int mid = (lo + hi)/2;
        if (ar[mid] == key)
            return mid;
        else if (ar[mid] < key)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Array Size: ";
    cin >> n;
    int ar[n];
    cout << "Array Elements: ";
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    sort(ar, ar+n);
    cout << "Enter element to search: ";
    int key;
    cin >> key;
    int index = binarySearch(ar,n,key);
    if (index != -1)
        cout << key << " found at " << index << "! :)" << endl;
    else
        cout << key << " not found! :(" << endl;
    return 0;
}