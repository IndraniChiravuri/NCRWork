#include <iostream>
#include <cmath>
#include<vector>
#include <stdlib.h>

using namespace std;

class Matrix {
    vector< vector<int> > mat;
public:
    Matrix() {}
    Matrix(int rows, int cols) {
        cout << "Enter Elements: " << endl;
        for (int i = 0; i < rows; i++) {
            vector<int> row;
            for (int j = 0; j < cols; j++) {
                int e;
                cin >> e;
                row.push_back(e);
            }
            mat.push_back(row);
        }
    }

    void display() {
        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }

    friend Matrix multiply(Matrix &m1, Matrix &m2);
};

Matrix multiply(Matrix &m1, Matrix &m2) {
    int s = 0;
    Matrix res;
    int r1 = m1.mat.size();
    int c1 = m1.mat[0].size();
    int r2 = m2.mat.size();
    int c2 = m2.mat[0].size();
    if (c1 != r2) {
        cout << "Multiplication is not possible" << endl;
        _Exit(-1);
    }
    vector< vector<int> > ans;
    for (int i = 0; i < r1; i++) {
            vector<int> row;
        for (int j = 0; j < c2; j++) {
            s = 0;
            for (int k = 0; k < r2; k++) {
                s = s +  m1.mat[i][k] * m2.mat[k][j];
            }
            row.push_back(s);
        }
        ans.push_back(row);

    }
    res.mat = ans;
    return res;
}

int main() {
    int r, c;
    cout << "Enter 1st matrix rows and columns: ";
    cin >> r >> c;
    Matrix m1(r,c);
    cout << "Enter 2nd matrix rows and columns: ";
    cin >> r >> c;
    Matrix m2(r,c);
    Matrix res = multiply(m1, m2);
    cout << "Result: "
    res.display();
    return 0;
}s