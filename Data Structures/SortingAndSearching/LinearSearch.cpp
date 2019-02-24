#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int linearSearch(int ar[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (ar[i] == key)
            return i;
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
    cout << "Enter element to search: ";
    int key;
    cin >> key;
    int index = linearSearch(ar,n,key);
    if (index != -1)
        cout << key << " found at " << index << "! :)" << endl;
    else
        cout << key << " not found! :(" << endl;
    return 0;
}