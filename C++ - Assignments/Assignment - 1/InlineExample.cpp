#include <iostream>

using namespace std;

inline int add(int x, int y) {
    return x + y;
}

inline int diff(int x, int y) {
    return x - y;
}

inline long int product(int x, int y) {
    return x * y;
}

inline float divide(int x, int y) {
    return x / y;
}

inline int mod(int x, int y) {
    return x % y;
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << "Addition: " << add(x,y) << endl;
    cout << "Difference: " << diff(x,y) << endl;
    cout << "Product: " << product(x,y) << endl;
    cout << "Division: " << divide(x,y) << endl;
    cout << "Modulus: " << mod(x,y) << endl;
    return 0;
}