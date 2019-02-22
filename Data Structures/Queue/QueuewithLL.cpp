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

    void enqueue(int );

    int dequeue();

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

void Queue::enqueue(int x) {//LINKED LIST INSERT FIRST FUNCTION
    struct Node *newNode = createNode(x);
	newNode -> next = start;
	start = newNode;
}

int Queue::dequeue() { //LINKED LIST DELETE LAST FUNCTION
    if (start == NULL) {
        cout << "Empty queue! :(" << endl;
        return INT_MIN;
    }
    struct Node *curr = start;
    while(curr -> next -> next != NULL)
        curr = curr -> next;
    //struct Node *temp = curr;
    int x = curr->next->data;
    delete curr->next;
    curr -> next = NULL;
    return x;
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
        cout << "1. Insert 2. Delete 3. Display 4.Exit" << endl;
        int choice;
        cin >> choice;
        switch(choice) {
            case 1:
                int ele;
                cout << "Enter element to be inserted: ";
                cin >> ele;
                q.enqueue(ele);
            break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            default:
                cout << "--EXITED--" << endl;
                exit(0);
        }
    }
    return 0;
}