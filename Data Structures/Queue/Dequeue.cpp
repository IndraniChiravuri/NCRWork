#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};
class Queue {
    struct Node *start;
public:
    Queue() {
        start = NULL;
    }

    struct Node* createNode(int );

    void push_first(int );
    void push_last(int );

    void pop_first();
    void pop_last();

    void display();

    ~Queue() {
        struct Node *temp;
        while (start != NULL) {
            temp = start;
            start = temp -> next;
            delete temp;
        }
        delete start;
    }
};

struct Node* Queue::createNode(int x) {
    struct Node *temp = new Node;
    temp -> data = x;
    temp -> next = NULL;
    return temp;
};

void Queue::push_first(int x) {//LINKED LIST INSERT FIRST FUNCTION
    struct Node *newNode = createNode(x);
	newNode -> next = start;
	start = newNode;
}

void Queue::push_last(int x) {
    if (start == NULL) {
        push_first(x);
        return ;
    }
    struct Node *newNode = createNode(x);
    struct Node *curr = start;
    while (curr->next != NULL) // MOVING TO THE LAST ELEMENT (STOPS AT LAST ELE)
        curr = curr->next;
    curr->next = newNode;
}

void Queue::pop_first() {
    if (start == NULL) {
        cout << "Empty List! :(" << endl;
        return;
    }
    struct Node *temp = start;
    start = start -> next;
    cout << "Deleted: " << temp->data << endl;
    delete temp;
    return;
}

void Queue::pop_last() { //LINKED LIST DELETE LAST FUNCTION
    if (start == NULL) {
        cout << "Empty queue! :(" << endl;
        return;
    }
    struct Node *curr = start;
    while(curr -> next -> next != NULL)
        curr = curr -> next;
    cout << "Deleted: " << curr->next->data << endl;
    delete curr->next;
    curr -> next = NULL;
    return;
}

void Queue::display() { //  LINKED LIST TRAVERSE FORWARD
    if (start == NULL) {
        cout << "Empty Queue! :(" << endl;
        return;
    } else {
        cout << "Element in Queue: ";
        struct Node *curr = start;
        while (curr != NULL) {
            cout << curr -> data << " ";
            curr = curr -> next;
        }
        cout << endl;
    }
}

int main() {
    Queue q;
    while(1) {
        cout << "1. Insert First 2. Insert Last 3. Delete First 4. Delete Last 5. Display 6.Exit" << endl;
        int choice;
        cin >> choice;
        int ele;
        switch(choice) {
            case 1:
                cout << "Enter element to be inserted: ";
                cin >> ele;
                q.push_first(ele);
            break;
            case 2:
                cout << "Enter element to be inserted: ";
                cin >> ele;
                q.push_last(ele);
                break;
            case 3:
                q.pop_first();
                break;
            case 4:
                q.pop_last();
                break;
            case 5:
                q.display();
                break;
            default:
                cout << "--EXITED--" << endl;
                exit(0);
        }
    }
    return 0;
}