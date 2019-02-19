#include <iostream>
#include <cstring>

using namespace std;

class Shape {
public:
    virtual void displayArea() {
        cout << "Shape's Display Area" << endl;
    }
};

class Triangle : public Shape {
public:
    void displayArea() {
        cout << "Triangle's Display Area" << endl;
    }
};

class Square : public Shape {
public:
    void displayArea() {
        cout << "Square's Display Area" << endl;
    }
};

class Rectangle : public Shape {
public:
    void displayArea() {
        cout << "Rectangle's Display Area" << endl;
    }
};

int main() {
    Shape *ptr;
    //ptr -> displayArea();
    Triangle T;
    ptr = &T;
    ptr -> displayArea();
    Square S;
    ptr = &S;
    ptr -> displayArea();
    Rectangle R;
    ptr = &R;
    ptr -> displayArea();
    return 0;
}