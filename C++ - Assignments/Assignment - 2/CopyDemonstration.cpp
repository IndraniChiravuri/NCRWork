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
        len = strlen(s)+1;
		str = new char[len ];
		strcpy(str,s);
    }
    String(const String &s) {
        len = s.len;
        str = new char[len+1];
        strcpy(str,s.str);
    }

    ~String() {
        if (str != NULL)
            delete str;
    }
    friend ostream& operator<<(ostream& out, String s);
 };

ostream& operator<<(ostream &out, String s) {
    out << s.str << endl;
    return out;
 }

int main() {
    String s1("Arya");
    String s2("Stark"),s3(s1);
    cout << s3 << endl;
    return 0;
}