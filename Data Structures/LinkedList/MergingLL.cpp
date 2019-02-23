#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};
class List {
    struct Node *start;
public:
    List() {
        start = NULL;
    }

    List(int ar[], int n) {
        start = createNode(ar[0]);
        for (int i = 1; i < n; i++)
            insertLast(ar[i]);
    }

    struct Node* createNode(int );
    void insertLast(int );
    void display();
    void mergeLL(List , List);
    void addToList(int );

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
    return temp;
};

void List::insertLast(int x) {
    struct Node *newNode = createNode(x);
    struct Node *curr = start;
    while (curr->next != NULL) // MOVING TO THE LAST ELEMENT (STOPS AT LAST ELE)
        curr = curr->next;
    curr->next = newNode;
}

void List::display() {
    if (start == NULL) {
        cout << "Empty List! :(" << endl;
        return;
    } else {
        struct Node *curr = start;
        while (curr != NULL) {
            cout << curr -> data << " ";
            curr = curr -> next;
        }
        cout << endl;
    }
}

void List::addToList(int ele) {
    struct Node *newNode = createNode(ele);
    if (start == NULL) {
        start = newNode;
        return;
    } else {
        insertLast(ele);
    }
}

void List::mergeLL(List l1, List l2) {
    struct Node* curr1 = l1.start;
    struct Node* curr2 = l2.start;
    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->data <= curr2->data) {
            addToList(curr1->data);
            curr1 = curr1->next;
        } else {
            addToList(curr2->data);
            curr2 = curr2->next;
        }
    }
    if (curr1 != NULL) {
        cout << curr1->data << " ";
        addToList(curr1->data);
        curr1 = curr1->next;
    }
    if (curr2 != NULL) {
        addToList(curr2->data);
        curr2 = curr2->next;
    }
    return;
}

int main() {
    int n;
    cout << "Enter length of first linked list: ";
    cin >> n;
    int ar[n];
    cout << "Enter linked list1 elements: ";
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    List l1(ar,n);
    l1.display();
    cout << "Enter length of second linked list: ";
    cin >> n;
    cout << "Enter linked list2 elements: ";
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    List l2(ar,n);
    l2.display();
    List l3;
    l3.mergeLL(l1,l2);
    cout << "Merged List: ";
    l3.display();
    return 0;
}