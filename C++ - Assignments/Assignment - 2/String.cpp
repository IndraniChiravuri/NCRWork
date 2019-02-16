#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class String {
    int len;
    char* str;
public:
    String() {
        str = NULL;
        len = 0;
    }
    String(char *s) {
        //cout << "In P.Constructor" << endl;
        len = strlen(s)+1;
		str = new char[len ];
		strcpy(str,s);
    }
    String(const String &s) {
        len = s.len;
        str = new char[len+1];
        strcpy(str,s.str);
    }

    String operator+(String s);
    char& operator[](int i);
    String operator=(String s);
    friend ostream& operator<<(ostream& out, String s);
    friend istream& operator>>(istream& in, String &s);

    ~String() {
        if (str != NULL)
            delete str;
    }
 };

 String String::operator=(String s) {
    len = s.len;
    if (str != NULL)
        delete str;
    str = new char[len + 1];
    strcpy(str, s.str);
    return *this;
 }

 char& String::operator[](int i) {
    if (i > len) {
        cout << "Array index out of bound" << endl;
        exit(-1);
        //return '\0';
    }
    return str[i];
 }

 String String::operator+(String s) {
     //cout << "In operator+" << endl;
    String res;
    res.len = len + s.len + 2;
    res.str = new char[res.len];
    strcpy(res.str, str);
    strcat(res.str, " ");
    strcat(res.str,s.str);
    return res;
 }

 istream& operator>>(istream &in, String &s) {
    s.str = new char[30];
    cout << "String: ";
    in >> s.str;
    s.len = strlen(s.str) + 1;
    return in;
 }

 ostream& operator<<(ostream &out, String s) {
    out << "String: " << s.str << endl;
    return out;
 }



int main() {
    String s1;
    cin >> s1;
    String s2,s3;
    cin >> s2;
    s3 = s1 + s2;
    cout << "Overloaded +(s1+s2): ";
    cout << s3 << endl;
    //cout << s1 << endl;
    //cout << s2 << endl;
    s3 = s2;
    cout << "Overloaded =(s3=s2): ";
    cout << s3 << endl;
    cout << "Element at ith pos(s3[0]): ";
    cout << s3[0] << endl;
    cout << "Replacing character at ith pos(s1[0] = 'I'): ";
    s1[0] = 'I';
    cout << s1 << endl;
    return 0;
}