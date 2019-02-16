#include <iostream>
#include <cstring>

using namespace std;

class Employee {
    int id;
    string name;
    int salary;
public:
    Employee() {}
    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }

    friend istream& operator>>(istream& , Employee &);
    ~Employee(){}
 };

 istream& operator>>(istream &in, Employee &e) {
    cout << "Id: ";
    in >> e.id;
    cout << "Name: ";
    in >> e.name;
    cout << "Salary: ";
    in >> e.salary;
    return in;
 }

int main() {
    Employee e[5];
    for (int i = 0; i < 5; i++) {
        cin >> e[i];
    }
    cout << "Employee Details: " << endl;
    for (int i = 0; i < 5; i++) {
        e[i].display();
    }
    return 0;
}