#include <iostream>
#include <cmath>

using namespace std;

class Polar {
    int angle;
    int radius;
public:
    static int objCnt;
    Polar() {
        objCnt++;
    }
    Polar(int angle, int radius) {
        this -> angle = angle;
        this -> radius = radius;
        objCnt++;
    }
    ~Polar() {
        objCnt--;
    }
 };

 int Polar:: objCnt;

 int main() {
    Polar p1;
    Polar p2(45,78);
    cout << "No. of active objects: " << Polar::objCnt << endl;
    {
        Polar p3, p4;
        cout << "No. of active objects: " << Polar::objCnt << endl;
    }
    Polar p5;
    cout << "No. of active objects: " << Polar::objCnt << endl;
    return 0;
 }