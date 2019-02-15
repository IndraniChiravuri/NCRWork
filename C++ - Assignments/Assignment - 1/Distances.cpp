#include <iostream>
#include <cmath>

using namespace std;

class Distance2;

class Distance1 {
    int meters;
    int cms;
public:
    Distance1(int meters, int cms) {
        this -> meters = meters;
        this -> cms = cms;
    }
    friend void addDistances(Distance1 &, Distance2 &);
};

class Distance2 {
    int feet;
    int inches;
public:
    Distance2(int feet, int inches) {
        this -> feet = feet;
        this -> inches = inches;
    }
    friend void addDistances(Distance1 &, Distance2 &);
};

void addDistances(Distance1 &d1, Distance2 &d2) {
     /*if (choice == 1) { // Converting from feet and inches to m and cms.
    } else { // Converting into meters and cms.
        d1.meters =
        d1.cms =
    } */
    d2.feet *= 0.348;
    d2.inches *= 2.54;
    cout << "Result(m & cms): " << d1.meters + d2.feet << "' " << d1.cms + d2.inches << endl;
}
int main() {
    /*cout << "1. Result in meters and cms\n2. Result in feet and inches" << endl;
    int choice;
    cin >> choice; */
    int x,y;
    cin >> x >> y;
    Distance1 d1(x,y);
    cin >> x >> y;
    Distance2 d2(x,y);
    addDistances(d1, d2);
    return 0;
}