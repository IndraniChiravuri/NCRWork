#include <iostream>

using namespace std;

void swap_value(int x, int y) {
    x = x + y;
    y = x - y;
    x = x - y;
    cout << "After Swapping: " << x << " " << y << endl;
}

void swap_reference(int &x, int&y) {
    x = x + y;
    y = x - y;
    x = x - y;
    cout << "After Swapping: " << x << " " << y << endl;
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << "1. Swap by value " << endl << "2. Swap by reference: " << endl;
    int choice;
    cin >> choice;
    cout << "Before Swapping: " << x  << " " << y << endl;
    switch(choice) {
        case 1: swap_value(x,y); break;
        case 2: swap_reference(x,y); break;
        default: cout << "Enter valid option" << endl;
    }
    return 0;
}