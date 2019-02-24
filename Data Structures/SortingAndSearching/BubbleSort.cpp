#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void swap(int &x, int &y) {
    x = x + y;
    y = x - y;
    x = x - y;
}

void bubbleSort(int ar[], int n) {
    bool flag = true; // REPRESENTS IF SWAPS ARE OCCURING ARE NOT.
    for(int i = 0; i < n - 1 && flag; i++) {
        flag = false;
		for(int j = 0; j < n - 1; j++) {
			if(ar[j] > ar[j+1]) {
                swap(ar[j], ar[j+1]);
				flag=true;
			}
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
    bubbleSort(ar,n);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
    cout << endl;
}