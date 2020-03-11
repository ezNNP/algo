#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//  типы фигур
//  1   2   3   4
//  X   XX   X  XX
//  XX  X   XX   X

int counter = 1;

void generate(int n, int x, int y, int hx, int hy, vector<vector<int>>& a) {
    if (n > 2) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (x + j * n/2 > hx || hx >= x + j*n/2 + n/2 || y + i*n/2 > hy || hy >= y + i*n/2 + n/2) {
                    a[y + n/2 - 1 + i][x + n/2 - 1 + j] = counter;
                }
            }
        }
        ++counter;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (!(x + j * n/2 > hx || hx >= x + j*n/2 + n/2 || y + i*n/2 > hy || hy >= y + i*n/2 + n/2)) {
                    generate(n/2, x + j*n/2, y + i*n/2, hx, hy, a);
                } else {
                    generate(n/2, x + j*n/2, y + i*n/2, x + n/2 - 1 + j, y + n/2 - 1 + i, a);
                }
            }
        }
    } else {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (i + y != hy || j + x != hx) {
                    a[i + y][j + x] = counter;
                }
            }
        }
        ++counter;
    }
}


int main(int argc, const char * argv[]) {
    int n, hx, hy;
    cin >> n >> hy >> hx;
    vector<vector<int>> a(pow(2, n), vector<int>(pow(2, n), -1));

    a[hy - 1][hx - 1] = 0;

    generate(pow(2, n), 0, 0, hx - 1, hy - 1, a);

    for (int i = 0; i < pow(2, n); ++i) {
        for (int j = 0; j < pow(2, n); ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}