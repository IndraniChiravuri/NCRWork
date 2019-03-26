#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

// LINKED LIST STRUCTURE
struct Node {
    int data;
    struct Node *next;
};

class List {
    struct Node *start; // LL STRUCTURE VARIABLE
public:
    List() {
        start = NULL;
    }

    struct Node* createNode(int );

    void insertFirst(int );
    void insertAt(int , int );

    int deleteElement(int );

    void traverseForward();
    void traverseBackward();
    void printBackwards(struct Node*);

    void reverseLL();

    ~List() {
        struct Node *temp;
        while (start != NULL) { // VISITING EVERY NODE INDIVIDUALLY AND REMOVING MEMORY
            temp = start;
            start = temp -> next;
            delete temp;
        }
        delete start; // DELETING FINAL NODE
    }
};

struct Node* List::createNode(int x) { // CREATING A NEW NODE
    struct Node *temp = new Node;
    temp -> data = x;
    temp -> next = NULL;
    return temp;
};

void List::insertFirst(int x) {
    struct Node *newNode = createNode(x);
	newNode -> next = start;
	start = newNode;
}

void List::insertAt(int ele, int pos=1) {
    // IF THE LIST IS EMPTY OR POS IS 1
    if (start == NULL || pos == 1) {
        insertFirst(ele);
        return ; // SUCCESSFULL INSERTION
    }
    struct Node *newNode = createNode(ele);
    struct Node *curr = start;
    for (int i = 1; i < pos-1; i++) // STOPS AT PREVIOUS ELEMENT
        curr = curr->next;
    if (curr == NULL) {
        cout << "Invalid Location" << endl;
        return; // ELE NOT INSERTED
    }
    // POSITION FOUND
    newNode->next = curr->next;
    curr->next = newNode;
}

int List::deleteElement(int ele) {
    if (start == NULL) { // NO LIST FOUND
        cout << "Empty List! :(" << endl;
        return INT_MIN;
    }
    struct Node *curr = start;
    int x;
    if (curr -> data == ele) { // ELEMENT IS AT 1ST POSITION
        start = curr -> next;
        x = curr -> data;
        delete curr;
    } else {
        while (curr -> next != NULL && curr -> next -> data != ele) // TRAVERSING TO THE LIST
            curr = curr -> next;
        if (curr -> next != NULL) { //ELEMET FOUND
            x = curr -> next -> data;
            struct Node *temp = curr -> next;
            curr -> next = temp -> next;
            delete temp;
        } else {
            cout << "Element not found! :(" << endl;
            return INT_MIN;
        }
    }
    return x;
}

void List::traverseForward() {
    if (start == NULL) {
        cout << "Empty List! :(" << endl;
        return;
    } else {
        cout << "Element in Linked List: ";
        struct Node *curr = start;
        while (curr != NULL) {
            cout << curr -> data << " ";
            curr = curr -> next;
        }
        cout << endl;
    }
}

void List::printBackwards(struct Node *curr) {
    if (curr == NULL)
        return;
    printBackwards(curr->next);
    cout << curr -> data << " ";
}

void List::traverseBackward() {
    if (start == NULL) {
        cout << "Empty List! :(" << endl;
        return;
    } else {
        cout << "Element in Linked List: ";
        printBackwards(start);
    }
    cout << endl;
}

void List::reverseLL() {
    if(start == NULL) {
        cout << "Empty List! :(" << endl;
        return ;
    } else {
		struct Node *curr = start; // RUNIING POINTER
		struct Node *prev = NULL;
		struct Node *temp = NULL;
		while (curr != NULL) {
			temp = curr->next;
			curr->next = prev; // DELINKING NODE
			prev = curr;
			curr = temp; // LINKING NODE
		}
		start = prev;
    }
}

int main() {
    List ll;
    while(1) {
        cout << "1. Insert 2. Delete Element 3. Display 4. Reverse the linked list 5.Exit" << endl;
        int choice, op;
        cin >> choice;
        switch(choice) {
            case 1:
                int ele, pos;
            cout << "Enter element to be inserted: ";
            cin >> ele;
            cout << "Enter Position(Index starts from 1): ";
            cin >> pos;
            ll.insertAt(ele, pos);
            break;
            case 2:
                cout << "Enter element to be deleted: ";
                cin >> ele; // Element to be deleted
                ll.deleteElement(ele);
                break;
            case 3:
                cout << "1. Display Forward 2. Display Backward" << endl;
                cin >> op;
                switch (op) {
                    case 1:
                        ll.traverseForward();
                        break;
                    case 2:
                        ll.traverseBackward();
                        break;
                }
                break;
            case 4:
                ll.reverseLL();
                break;
            default:
                cout << "--EXITED--" << endl;
                exit(0);
        }
    }
    return 0;
}
