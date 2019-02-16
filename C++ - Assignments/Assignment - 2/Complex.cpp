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

    Complex(const Complex& c) {
        this->real = c.real;
        this->img = c.img;
    }

    Complex operator+(Complex c) {
        Complex res;
        res.real = this -> real + c.real;
        res.img = this -> img + c.img;
        return res;
    }

    Complex operator-(Complex c) {
        Complex res;
        res.real = this -> real - c.real;
        res.img = this -> img - c.img;
        return res;
    }

    Complex operator-() {
        Complex res;
        res.real = -this -> real;
        res.img = -this -> img;
        return res;
    }

    Complex operator++() {
        ++real;
        ++img;
        return *this;
    }

    Complex operator++(int x) {
        Complex res;
        res.real = real++;
        res.img = img++;
        return res;
    }

    Complex operator=(Complex c) {
        this -> real = c.real;
        this -> img = c.img;
        return *this;
    }

    Complex operator,(Complex c) {
        return c;
    }

    Complex* operator->() {
        return this;
    }
   void display() {
  	cout << "In Display Function" << endl; 
  }

    friend istream& operator>>(istream &, Complex &);
    friend ostream& operator<<(ostream &, Complex &);

    ~Complex() {}
};

istream& operator>>(istream& in, Complex &c) {
    cout << "Real part: ";
    in >> c.real;
    cout << "Imaginary Part: ";
    in >> c.img;
    return in;
}

ostream& operator<<(ostream& out, Complex c) {
    if (img < 0)
            out << c.real << c.img << "i" << endl;
    else
            out << c.real << " + " << c.img << "i" << endl;
}

int main() {
    Complex c1;
    cin >> c1;
    Complex c2;
    cin >> c2;
    Complex c3(c2);
    
    Complex c4 = c1 + c2;
    cout << "Addition: ";
    cout << c4;
    c4 = c1 - c2;
    cout << "Subtraction: ";
    cout << c4;
    c4 = -c3;
    cout << "-ve: ";
    cout << c4;
    c4 = ++c2;
    cout << "Pre Increment: ";
    cout << c4;
    c4 = c1++;
    cout << "Post Increment: ";
    cout << c4;
    c4 = c1,c2,c3;
    cout << "Comma Operator: ";
    cout << c4;
    c4->display();
    return 0;
}