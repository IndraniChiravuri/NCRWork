#include <iostream>
#include <cstring>

using namespace std;

class Student {
    int id;
    string name;
    int m1, m2, m3;
    int total_marks;
    string grade;
public:
    Student() {}
    friend ostream& operator<<(ostream& out, Student s);
    friend istream& operator>>(istream& in, Student &s);
    friend void generateResults(Student s[], int n);
 };

 istream& operator>>(istream &in, Student &s) {
    cout << "Id: ";
    in >> s.id;
    cout << "Name: ";
    //in >> s.name;
    //string nm;
    getline(in, s.name);
    //s.name = nm;
    cout << "Enter marks of 3 subjects: ";
    in >> s.m1 >> s.m2 >> s.m3;
    s.total_marks = s.m1 + s.m2 + s.m3;
    return in;
 }

 ostream& operator<<(ostream &out, Student s) {
    out << "Id: " << s.id << endl;
    out << "Name: " << s.name << endl;
    out << "Marks 1: " << s.m1 << endl;
    out << "Marks 2: " << s.m2 << endl;
    out << "Marks 3: " << s.m3 << endl;
    out << "Total: " << s.total_marks << endl;
    out << "Grade: " << s.grade << endl;
 }

 void generateResults(Student s[], int n) {
    for (int i = 0; i < n; i++) {
        int avg = (int)(s[i].total_marks/3);
        if (avg >= 60)
            s[i].grade = "First Class";
        else if (avg < 60 && avg >= 50)
            s[i].grade =  "Second Class" ;
        else if (avg < 50 && avg >= 40)
            s[i].grade = "Third Class";
        else

            s[i].grade = "Fail";
    }
 }

int main() {
    int n;
    cin >> n;
    Student s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    generateResults(s,n);
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }
    return 0;
}