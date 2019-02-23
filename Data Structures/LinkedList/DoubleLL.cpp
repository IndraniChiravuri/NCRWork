#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};
class List {
    struct Node *start;
public:
    List() {
        start = NULL;
    }

    struct Node* createNode(int );
    void insertFirst(int );
    void insertLast(int );
    void insertAfter(int , int );
    void insertBefore(int , int );

    int deleteFirst();
    int deleteLast();
    int deleteElement(int );

    void traverseForward();
    void traverseBackward();

    void reverseLL();

    ~List() {
        struct Node *temp;
        while (start != NULL) {
            temp = start;
            start = temp -> next;
            delete temp;
        }
        delete start;
    }
};

struct Node* List::createNode(int x) {
    struct Node *temp = new Node;
    temp -> data = x;
    temp -> next = NULL;
    temp -> prev = NULL;
    return temp;
};

void List::insertFirst(int x) {
    struct Node *newNode = createNode(x);
    newNode -> next = start;
    if (start != NULL)
        start -> prev = newNode;
	start = newNode;
}

void List::insertLast(int x) {
    if (start == NULL) {
        insertFirst(x);
        return ;
    }
    struct Node *newNode = createNode(x);
    struct Node *curr = start;
    while (curr->next != NULL) // MOVING TO THE LAST ELEMENT (STOPS AT LAST ELE)
        curr = curr->next;
    curr->next = newNode;
    newNode->prev = curr;
}

void List::insertAfter(int x, int ele) {
    if (start == NULL) {
        cout << "List is empty! :(" << endl;
        return;
        //insertFirst(x);
    }
    struct Node *newNode = createNode(x);
    struct Node *curr = start;
    while (curr != NULL && curr->data != ele)
        curr = curr->next;
    if (curr  == NULL) { // IF IT'S THE LAST ELEMENT
        cout << "Element not found! :(" << endl;
        return;
    } else if (curr->data == ele) { // ELEMENT FOUND
        newNode -> next = curr -> next;
        newNode -> prev = curr;
        curr -> next = newNode;
        if (curr->next != NULL)
            curr->next->prev = newNode;
    }
}

void List::insertBefore(int x, int ele) {
    if (start == NULL) {
        cout << "List is empty" << endl;
        return ;
    }
    struct Node *newNode = createNode(x);
    struct Node *curr = start;
    while (curr != NULL && curr->data != ele)
        curr = curr->next;
    if (curr == NULL) {
        cout << "Element not found! :(" << endl;
        return;
    } else if (curr->data == ele) { //ELEMENT FOUND
        newNode->next = curr;
        newNode->prev = curr -> prev;
        if (curr -> prev != NULL) {
            curr -> prev -> next = newNode;
            curr -> prev = newNode;
        } else {
            curr -> prev = newNode;
            start = newNode;
        }
    }
}

int List::deleteFirst() {
    if (start == NULL) {
        cout << "Empty List! :(" << endl;
        return INT_MIN;
    }
    struct Node *temp = start;
    start = start -> next;
    if (start != NULL)
        start -> prev = NULL;
    int x = temp->data;
    delete temp;
    return x;
}

int List::deleteLast() {
    if (start == NULL) {
        cout << "Empty List! :(" << endl;
        return INT_MIN;
    }
    struct Node *curr = start;
    while(curr -> next != NULL)
        curr = curr -> next;
    //struct Node *temp = curr;
    int x = curr->data;
    curr->prev->next = NULL;
    curr -> prev = NULL;
    delete curr;
    return x;
}

int List::deleteElement(int ele) {
    if (start == NULL) {
        cout << "Empty List! :(" << endl;
        return INT_MIN;
    }
    struct Node *curr = start;
    int x;
    if (curr -> data == ele) {
        deleteFirst();
    } else {
        while (curr->next != NULL && curr -> data != ele)
            curr = curr -> next;
        if (curr->next != NULL) { //ELEMET FOUND
            x = curr -> data;
           // struct Node *temp = curr;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            //curr -> next = temp -> next;
            delete curr;
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

void List::traverseBackward() {
    if (start == NULL) {
        cout << "Empty List! :(" << endl;
        return;
    } else {
        cout << "Element in Linked List: ";
        struct Node *curr = start;
        while (curr -> next != NULL)
            curr = curr -> next;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr -> prev;
        }
    }
    cout << endl;
}

void List::reverseLL() {
    if(start == NULL) {
        cout << "Empty List! :(" << endl;
        return ;
    } else {
		struct Node *curr = start;
		struct Node *prev = NULL;
		struct Node *temp = NULL;
		while (curr != NULL) {
			temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		start = prev;
    }
}

int main() {
    List ll;
    while(1) {
        cout << "1. Insert 2. Delete 3. Display 4. Reverse the linked list 5.Exit" << endl;
        int choice,x, op;
        cin >> choice;
        switch(choice) {
            case 1:
                int ele;
            cout << "Enter element to be inserted: ";
            cin >> ele;
            cout << "1. Insert at beginning 2. Insert at the end 3. Insert after an element 4. Insert before an element" << endl;
            cin >> op;
            switch(op) {
                case 1:
                    ll.insertFirst(ele);
                    break;
                case 2:
                    ll.insertLast(ele);
                    break;
                case 3:
                    cout << "Enter Element: ";
                    cin >> x; //x -- Element where ele to be inserted
                    ll.insertAfter(ele,x);
                    break;
                case 4:
                    cout << "Enter Element: ";
                    cin >> x; //x -- Element where ele to be inserted
                    ll.insertBefore(ele,x);
                    break;
            }
            break;
            case 2:
                cout << "1. Delete First Element 2. Delete Last Element 3. Delete specific element" << endl;
                cin >> op;
                switch(op) {
                    case 1:
                        ll.deleteFirst();
                        break;
                    case 2:
                        ll.deleteLast();
                        break;
                    case 3:
                        int ele; // Element to be deleted
                        cout << "Enter element to be deleted: ";
                        cin >> ele;
                        ll.deleteElement(ele);
                        break;
                }
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