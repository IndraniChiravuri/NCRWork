#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>

using namespace std;

struct StackStruct {
    int top;
    int *s;
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

        Stack(int n) {
            stk.top = -1;
            stk.st_size = n;
            stk.s = new int[n];
        }

        bool isEmpty() {
            return stk.top == -1;
        }

        bool isFull() {
            return stk.top == stk.st_size-1;
        }

        void push(int item) {
            if (isFull()) {
                cout << "Overflow\n";
                //exit(-1);
            } else {
                stk.s[++stk.top] = item;
                cout << "Pushed " << item << endl;
            }
        }

        int peek() {
            if (isEmpty()) {
                cout << "Underflow" << endl;
                return INT_MIN;
            }
            return stk.s[stk.top];
        }

        int pop() {
            if (isEmpty()) {
                cout << "Underflow" << endl;
                //exit(-1);
            } else {
                cout << "Poped " << peek() << endl;;
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


int main() {
    int n;
    cout << "Size: "
    cin >> n;
    Stack  _stack(n);
    while (1) {
        cout << "1. Push 2. Pop 3. Display 4. Peek 5. Exit" << endl;
        int choice;
        cin >> choice;
        switch(choice) {
            case 1:
                int n;
                cout << "Enter Element: ";
                cin >> n;
                _stack.push(n);
                break;
            case 2:
                _stack.pop();
                break;
            case 3:
                cout << "Stack Elements: " << endl;
                _stack.display();
                break;
            case 4:
                _stack.peek();
                break;
            default:
                //cout << "Invalid option" << endl;
                exit(-1);
        }
        cout << endl;
    }
    return 0;
}