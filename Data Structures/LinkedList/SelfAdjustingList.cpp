#include<iostream>
#include <cstdio>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

class SelfAdjustingList {
	struct Node *start;
public:
	SelfAdjustingList() {
		start=NULL;
	}

	SelfAdjustingList(int ar[], int n) {
        start = createNode(ar[0]);
        for (int i = 1; i < n; i++)
            addToList(ar[i]);
	}

	struct Node* createNode(int );
	void adjust(int);
	void addToList(int);
	void display();

	~SelfAdjustingList() {
		struct Node *temp;
        while (start != NULL) {
            temp = start;
            start = temp -> next;
            delete temp;
        }
        delete start;
	}
};

struct Node*  SelfAdjustingList::createNode(int x) {
    struct Node *temp = new Node;
    temp -> data = x;
    temp -> next = NULL;
    return temp;
}

void SelfAdjustingList::addToList(int x) {
	struct Node *newNode = createNode(x);
    struct Node *curr = start;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

void SelfAdjustingList::display() {
	struct Node *curr = start;
	if(start!=NULL) {
		while(curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
}

void SelfAdjustingList::adjust(int x) {
	struct Node* curr = start;
	struct Node* prev=NULL;
	if(start != NULL) {
		while(curr != NULL && curr->data != x) {
			prev = curr;
			curr = curr->next;
		}
		if(curr != NULL && prev != NULL) {
			prev -> next = curr -> next;
			curr->next = start;
			start = curr;
		}
	}
}

int main() {
	cout<<"Enter List Size: ";
	int n;
	cin >> n;
	int ar[n];
	cout << "Enter elements: ";
	for (int i = 0; i < n; i++)
        cin >> ar[i];
	SelfAdjustingList l(ar,n);
	l.display();
	while(1) {
        cout << "1. Search an element 2.Exit" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            int x;
            cout << "Enter Element: ";
            cin >> x;
            l.adjust(x);
            cout << "Adjusted List: ";
            l.display();
        } else
            break;
	}
	return 0;
}