#include <iostream>
#include <cmath>

using namespace std;

class Coordinate {
    int x;
    int y;
public :
    Coordinate(int x, int y) {
        this -> x = x;
        this -> y = y;
    }
     friend int findDistance(Coordinate &c1, Coordinate &c2);
};

int findDistance(Coordinate &c1, Coordinate &c2) {
    double x1 = pow((c2.x - c1.x), 2);
    double x2 = pow((c2.y - c1.y), 2);
    return sqrt(x1 + x2);
}
int main() {
    int x, y;
    cin >> x >> y;
    Coordinate c1(x,y);
    cin >> x >> y;
    Coordinate c2(x,y);
    cout << findDistance(c1,c2) << endl;
    return 0;
}