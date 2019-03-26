#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class String {
    int len;
    char* str;
public:
    String() {
        this->str = NULL;
        this->len = 0;
    }
    String(char *str) {
        //cout << "In P.Constructor" << endl;
        this->len = strlen(str)+1;
	   this->str = new char[len ];
	   strcpy(this->str,str);
    }
    String(const String &strObj) {
        this->len = strObj.len;
        this->str = new char[len+1];
        strcpy(this->str,strObj.str);
    }

    String operator+(String s);
    char& operator[](int i);
    String operator=(String s);
    friend ostream& operator<<(ostream& out, String );
    friend istream& operator>>(istream& in, String &);

    ~String() {
        if (this->str != NULL)
            delete this->str;
    }
 };

 String String::operator=(String strObj) {
    this->len = strObj.len;
    if (this->str != NULL)
        delete this->str;
    this->str = new char[this->len + 1];
    strcpy(this->str, strObj.str);
    return *this;
 }

 char& String::operator[](int i) {
    if (i > len) {
        cout << "Array index out of bound" << endl;
        exit(-1);
        //return '\0';
    }
    return this->str[i];
 }

 String String::operator+(String strObj) {
     //cout << "In operator+" << endl;
    String res;
    res.len = this->len + strObj.len + 2; // why +2 - 1 for " " and 1 for "\0"
    res.str = new char[res.len];
    strcpy(res.str, this->str);
    strcat(res.str, " ");
    strcat(res.str,strObj.str);
    strcat(res.str, "\0");
    return res;
 }

 istream& operator>>(istream &in, String &strObj) {
    strObj.str = new char[30];
    cout << "String: ";
    in >> strObj.str;
    strObj.len = strlen(strObj.str) + 1;
    return in;
 }

 ostream& operator<<(ostream &out, String strObj) {
    out << "String: " << strObj.str << endl;
    return out;
 }



int main() {
    String strObj1;
    cin >> strObj1;
    String strObj2,strObj3;
    cin >> strObj2;
    strObj3 = strObj1 + strObj2;
    cout << "Overloaded +(strObj1+strObj2): ";
    cout << strObj3 << endl;
    //cout << strObj1 << endl;
    //cout << strObj2 << endl;
    strObj3 = strObj2;
    cout << "Overloaded =(strObj3=strObj2): ";
    cout << strObj3 << endl;
    cout << "Element at ith pos(strObj3[0]): ";
    cout << strObj3[0] << endl;
    cout << "Replacing character at ith pos(strObj1[0] = 'I'):";
    strObj1[0] = 'I';
    cout << strObj1 << endl;
    return 0;
}