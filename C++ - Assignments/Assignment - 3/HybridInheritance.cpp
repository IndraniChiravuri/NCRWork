#include<iostream>

using namespace std;

class Person  {
    string name;
    int age;
public:
    Person() {
        name = "Joey Tribbiane";
        age = 20;
    }
    void displayPerson() {
			cout << "Name: " << name << endl;
			cout << "Age: " << age << endl;
    }
};

//virtually deriving class
class Physique : virtual public Person {
    int height;
    int weight;
public:
		Physique() {
			height = 6;
			weight = 55;
		}
		void displayPhysique() {
			cout << "Height:  "<< height << endl;
			cout << "Weight: " << weight << endl;
		}
};

class Family: virtual public Person {
	int childrenCnt;
    string religion;
	public:
		Family() {
			childrenCnt = 0;
			religion = "Catholic";
		}
		void displayFamily() {
			cout <<"Children: " << childrenCnt << endl;
			cout <<"Religion: " << religion << endl;
		}
};

class Employee: public Physique, public Family {
	int id;
    float salary;
	public:
		Employee() {
			id = 21;
			salary = 70000.0f;
		}
		void displayEmployee() {
			displayPerson();
			displayPhysique();
			displayFamily();
			cout << "Employee Id: " << id << endl;
			cout << "Salary: "  << salary << endl;
		}
};
int main() {
	Employee obj;
	obj.displayEmployee();
	return 0;
}