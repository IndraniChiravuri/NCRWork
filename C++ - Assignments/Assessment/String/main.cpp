#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class String {
    int len;
    char* str;
public:
    String() { //DEFAULT CONSTRUCTOR
        this->str = NULL;
        this->len = 0;
    }
    String(char *s) {
        this->len = strlen(s)+1;
		this->str = new char[this->len];
		strcpy(this->str,s);
    }
    String(const String &strObj) { // COPY CONSTRUCTOR
        this->len = strObj.len;
        this->str = new char[this->len+1];
        strcpy(this->str,strObj.str);
    }

    String operator+(String );
    bool operator<(String );
    String operator=(String );

    friend void sortStrings(String[] , int);
    friend ostream& operator<<(ostream& , String );
    friend istream& operator>>(istream& , String &);

    ~String() {
        if (this->str != NULL)
            delete str;
    }
 };

 String String::operator=(String strObj) {
    this->len = strObj.len;
    if (this->str != NULL)
        delete this->str; // FREEING MEMORY
    this->str = new char[this->len + 1];
    strcpy(this->str, strObj.str);
    return *this;
 }

 String String::operator+(String strObj) {
     //cout << "In operator+" << endl;
    String res;
    res.len = this->len + strObj.len + 1;
    res.str = new char[res.len];
    strcpy(res.str, this->str);
    //strcat(res.str, " ");
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
    //out << "String: " << s.str << endl;
    out << strObj.str << " ";
    return out;
 }

bool String::operator<(String strObj) {
    int len = min(this->len, strObj.len);
    for (int i = 0; i < len; i++) {
        if (this->str[i] > strObj.str[i])
            return false;
    }
    return true;
}

void swapStrings(String &string_1, String &string_2) {
	String temp;
	temp = string_1;
	string_1 = string_2;
	string_2 = temp;
}

void sortStrings(String strings[], int n) {
	bool flag = true; // REPRESENTS IF SWAPS ARE OCCURING ARE NOT.
	for (int i = 0; i < n && flag; i++) {
		flag = false;
		for (int j = i+1; j < n-1; j++) {
			if (!(strings[i] < strings[j])) {
				swapStrings(strings[i], strings[j]);
				flag = true;
			}
		}
	}
}


int main() {
    String strObj1;
    cin >> strObj1;
    String strObj2;
    cin >> strObj2;
    String strObj3;
    strObj3 = strObj1 + strObj2;
    String strObj4;
    strObj4 = strObj3;
    cout << "Assignment Operator: ";
    cout << strObj4 << endl;
    cout << "Overloaded +(s1+s2): ";
    cout << strObj3 << endl;
    int n = 3;
    String stringsArray[] = {strObj1, strObj2, strObj3};
    sortStrings(stringsArray, n);
    cout << "\nSorted:" << endl;
    for (int i = 0; i < n; i++)
        cout << stringsArray[i];
    return 0;
}
