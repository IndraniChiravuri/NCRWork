#include <iostream>
#include <cmath>

using namespace std;

class Employee {
    int id;
    string name;
public:
    Employee() {
        cout << "In default constructor" << endl;
    }
    Employee(int id, string name) {
        this -> id = id;
        this -> name = name;
        cout << "In parameterized constructor" << endl;
    }
    Employee(const Employee &e) {
        cout << "In copy constructor" << endl;
    }
    ~Employee() {
        cout << "In destructor" << endl;
    }
};

int main() {
    Employee e1; // Goes to default constructor.
    Employee e2(21, "Jon Snow"); // Goes to parameterized Constructor.
    Employee e3(e2); // Goes to Copy Constructor.
    cout << "Size of e1: " << sizeof(e1) << endl;
    cout << "Size of e2: " << sizeof(e2) << endl;
    cout << "Size of e3: " << sizeof(e3) << endl;
    // Destructor will be called implicitly.
    return 0;
}