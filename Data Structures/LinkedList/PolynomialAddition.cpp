#include<iostream>
using namespace std;
struct Node {
	int coeff;
	int power;
	struct Node *next;
};
class Polynomial {
	struct Node *start;
public:
	Polynomial() {
		start = NULL;
	}

	Polynomial(int len) {
	    start = NULL;
	    cout << "Enter polynomial coeffs and powers: " << endl;
        while(len--) {
            int coeff,power;
            cin >> coeff >> power;
            addToList(coeff,power);
        }
	}

	void addToList(int x,int y);
	void add(Polynomial p1,Polynomial p2);
	void display();

	~Polynomial() {
		while(start != NULL) {
			struct Node *temp = start;
			start = start->next;
			delete temp;
		}
		delete start;
	}
};

void Polynomial::display() {
	if(start!=NULL) {
		struct Node *curr = start;
		while(curr != NULL) {
			if (curr->coeff < 0)
				cout << curr->coeff << "x^" << curr->power << " ";
			else if (curr->coeff > 0)
				cout << "+" << curr ->coeff << "x^" << curr->power << " ";
			curr = curr->next;
		}
		cout << endl;
	}
}
void Polynomial::add(Polynomial p1,Polynomial p2) {
	int x,y;
	struct Node *curr1 = p1.start;
	struct Node *curr2 = p2.start;
	while (curr1 != NULL && curr2 != NULL) {
		if (curr1->power == curr2->power) {
			x = curr1->coeff + curr2->coeff;
			addToList(x, curr1->power);
			curr1 = curr1->next;
			curr2 = curr2->next;
		} else if (curr1->power < curr2->power) {
			addToList(curr2->coeff, curr2->power);
			curr2 = curr2->next;
		} else  {
			addToList(curr1->coeff, curr1->power);
			curr1 = curr1->next;
		}
	}
	while (curr1 != NULL) {
		addToList(curr1->coeff, curr1->power);
		curr1 = curr1->next;
	}
	while (curr2 != NULL) {
		addToList(curr2->coeff, curr2->power);
		curr2 = curr2->next;
	}
	return ;
}

void Polynomial::addToList(int x, int y) {
    //cout << "In Add TO List" << endl;
	struct Node *newNode = new Node;
	newNode -> coeff = x;
	newNode -> power = y;
	newNode -> next = NULL;
	if (start == NULL) {
        //cout << "In first IF" << endl;
		start = newNode;
	} else {
		struct Node *curr = start;
		while(curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = newNode;
	}
}

int main() {
    int len;
    cout << "Enter expression1 length: ";
    cin >> len;
    Polynomial p1(len);
    p1.display();
    cout << "Enter expression2 length: ";
    cin >> len;
    Polynomial p2(len);
	p2.display();
	Polynomial p3;
	p3.add(p1,p2);
	cout << "Result: ";
	p3.display();
	return 0;
}