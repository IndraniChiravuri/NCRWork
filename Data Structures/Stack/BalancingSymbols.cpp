#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>

using namespace std;

struct StackStruct {
    int top;
    char *s;
    int st_size;
};

class Stack {
    protected :
        struct StackStruct stk;
    public:
        Stack() {
            stk.top = -1;
            stk.s = NULL;
            stk.st_size = 0;
        }

        /* Stack(int n) {
            stk.top = -1;
            stk.st_size = n;
            stk.s = new char[n];
        } */

        void setStack(int len) {
            stk.st_size = len;
            stk.s = new char[len];
        }

        bool isEmpty() {
            return stk.top == -1;
        }

        bool isFull() {
            return stk.top == stk.st_size-1;
        }

        void push(char item) {
            if (isFull()) {
                cout << "Overflow\n";
                //exit(-1);
            } else {
                stk.s[++stk.top] = item;
                //cout << "Pushed " << item << endl;
            }
        }

        char peek() {
            if (isEmpty()) {
                cout << "Underflow" << endl;
                return '/0';
            }
            return stk.s[stk.top];
        }

        char pop() {
            if (isEmpty()) {
                cout << "Underflow" << endl;
                //exit(-1);
            } else {
                //cout << "Poped " << peek() << endl;;
                return (stk.s[stk.top--]);

            }
        }

        void display() {
            if (isEmpty()) {
                cout << "No elements in stack" << endl;
            } else {
                for (int i = stk.top; i > -1; i--) {
                    cout << stk.s[i] << " ";
                }
            }
            cout << endl;
        }

        ~Stack() {
            delete [] stk.s;
        }
};

class BalancingSymbols {
    string str;
    int len;
    Stack stk;
public:
    BalancingSymbols() {
    }

    BalancingSymbols(string str) {
        this -> str = str;
        this -> len = str.size();
        stk.setStack(len);
    }
    bool isBalanced() {
        for (int i = 0; i < len; i++) {
            char ch = this -> str[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                    stk.push(ch);
            }
            if (ch == ')' || ch == '}' || ch == ']') {
                if (!stk.isEmpty()) {
                    if ((ch == ')' && '(' == stk.peek()) || (ch == ']' && '[' == stk.peek()) || (ch == '}' && '{' == stk.peek())) {
                        stk.pop();
                    } else
                        return false;
                } else
                    return false;
            }
        }
        return true;
    }
};

int main() {
    string str;
    cout << "Enter Expression: ";
    getline(cin, str);
    BalancingSymbols  b(str);
    if(b.isBalanced())
        cout << "Balanced! ;)" << endl;
    else
        cout << "Not Balanced! :(" << endl;
    return 0;
}