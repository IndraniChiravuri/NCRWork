#include <iostream>

using namespace std;

class Complex {
    int real;
    int img;
public :
    Complex() {
        real = 0;
        img = 0;
    }
    Complex(int x) {
        real = x;
        img = x;
    }
    Complex(int r, int i) {
        real = r;
        img = i;
    }

    void print() {
        if (img < 0)
                cout << real << img << "i" << endl;
        else
            cout << real << " + " << img << "i" << endl;

    }
    friend void add(Complex &c1, Complex &c2);
    friend void multiply(Complex &c1, Complex &c2);
};

void add(Complex &c1, Complex &c2) {
    Complex c;
    c.real = c1.real + c2.real;
    c.img = c1.img + c2.img;
    cout << "Addition: ";
    c.print();
}

void multiply(Complex &c1, Complex &c2) {
    Complex c;
    c.real = c1.real * c2.real;
    c.img = c1.img * c2.img;
    cout << "Product: ";
    c.print();
}
int main() {
    Complex c1(4, 5);
    //cin >> c1.real >> c1.img;
    Complex c2(6);
    add(c1,c2);
    multiply(c1, c2);
    return 0;
}