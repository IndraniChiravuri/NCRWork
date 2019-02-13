#include <iostream>

using namespace std;

class Student {
    string name;
    string grade;
    int marks1;
    int marks2;
    int marks3;
public :
    void setData(string nm, string grd, int m1, int m2, int m3) {
        name = nm;
        grade = grd;
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;
    }
    void display() {
        cout << "Name: " << name << "\nGrade: " << grade << "\nMarks1: " << marks1 << "\nMarks2: " << marks2 << "\nMarks3: " << marks3 << endl;
    }

    int average(int m1, int m2, int m3) {
        return (int)((m1 + m2 + m3) / 3);
    }

    string computeGrade(int m1, int m2, int m3) {
        if (m1 < 40 || m2 < 40 || m3 < 40)
            return "Fail";
        int avg = average(m1, m2, m3);
        if (avg >= 60)
            return "First Class";
        else if (avg < 60 && avg >= 50)
            return "Second Class";
        else if (avg < 50 && avg >= 40)
            return "Third Class";
    }
};

int main() {
    Student st1;
    cout << "Enter name: ";
    string name;
    //cin >> name;
    getline(cin, name);
    cout << "Enter marks: ";
    int m1, m2, m3;
    cin >> m1 >> m2 >> m3;
    st1.setData(name, st1.computeGrade(m1, m2, m3), m1, m2, m3);
    st1.display();
    return 0;
}