#include <iostream>
#include <cstring>

using namespace std;

class Sample {
    int x;
protected:
    int y;
public:
    int z;
    Sample() {
        x = 9; y = 22; z = 8;
    }
    virtual void display() {
    }
};

class PublicDer : public Sample {
    //Since its a public derivation the access sepcifiers of base class members will not change
public:
    void display() {
        //cout << "x: " << x << endl; -- CANNOT BE ACCESSED 'COZ X IS PRIVATE VARIABLE.
        cout << "y: " << y << endl;
        cout << "z: " << z << endl;
    }
};

class ProtectedDer : protected Sample {
    //Since its a protected derivation y and z will become protected in derived class
public:
    void display() {
        //cout << "x: " << x << endl; -- CANNOT BE ACCESSED 'COZ X IS PRIVATE VARIABLE.
        //cout << "y: " << y << endl;
        cout << "z: " << z << endl;
    }
};

class PrivateDer : private Sample {
    //Since its a public derivation y and z will become private in derived class
public:
    void display() {
        //cout << "x: " << x << endl; -- CANNOT BE ACCESSED 'COZ X IS PRIVATE VARIABLE.
        //cout << "y: " << y << endl;
        cout << "z: " << z << endl;
    }
};

int main() {
    Sample *ptr;
    //cout << ptr -> x; -- CANNOT BE ACCESSED.
    //cout << ptr -> y << endl; -- PROTECTED MEMBERS CANNOT BE ACCESSED OUTSIDE THE CLASS.
    cout << "PTR->Z: " << ptr -> z << endl; // GIVES GARBAGE VALUE 'COZ PTR IS A POINTER NOT AN OBJECT.
    PublicDer obj1;
    ptr = &obj1;
    obj1.display();
    // IF THE DERIVED CLASSES ARE PROTECTED OR PRIVATE WE CANNOT ACCESS ANY MEMBERS.
    /*ProtectedDer obj2;
    ptr = &obj2;
    obj2.display();
    PrivateDer obj3;
    ptr = &obj3;
    obj3.display(); */

    return 0;
}