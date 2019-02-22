#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};
class Stack {
    struct Node *start;
public:
    Stack() {
        start = NULL;
    }

    struct Node* createNode(int );

    void push(int );

    int pop();

    int peek();

    void display();

    ~Stack() {
        struct Node *temp;
        while (start != NULL) {
            temp = start;
            start = temp -> next;
            delete temp;
        }
        delete start;
    }
};

struct Node* Stack::createNode(int x) {
    struct Node *temp = new Node;
    temp -> data = x;
    temp -> next = NULL;
    return temp;
};

void Stack::push(int x) { //LINKED LIST INSERT FIRST FUNCTION
    struct Node *newNode = createNode(x);
	newNode -> next = start;
	start = newNode;
}

int Stack::pop() { // LINKED LIST DELETE FIRST FUNCTION
    if (start == NULL) {
        cout << "Empty Stack! :(" << endl;
        return INT_MIN;
    }
    struct Node *temp = start;
    start = start -> next;
    int x = temp->data;
    delete temp;
    return x;
}

void Stack::display() { //  LINKED LIST TRAVERSE FORWARD
    if (start == NULL) {
        cout << "Empty Stack! :(" << endl;
        return;
    } else {
        cout << "Element in Stack: ";
        struct Node *curr = start;
        while (curr != NULL) {
            cout << curr -> data << " ";
            curr = curr -> next;
        }
        cout << endl;
    }
}

int Stack::peek() {
    if (start == NULL) {
        cout << "Empty Stack! :(" << endl;
        return INT_MIN;
    }
    return start->data;
}

int main() {
    Stack stk;
    while(1) {
        cout << "1. Push 2. Pop 3. Display 4. Peek 5.Exit" << endl;
        int choice;
        cin >> choice;
        switch(choice) {
            case 1:
                int ele;
                cout << "Enter element to be inserted: ";
                cin >> ele;
                stk.push(ele);
            break;
            case 2:
                stk.pop();
                break;
            case 3:
                stk.display();
                break;
            case 4:
                if (stk.peek() != INT_MIN)
                    cout << "Top Element: " << stk.peek() << endl;
                break;
            default:
                cout << "--EXITED--" << endl;
                exit(0);
        }
    }
    return 0;
}