#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define DOUBLE_MAX std::numeric_limits<double>::max()

using namespace std;

struct pumpkin {
    explicit pumpkin(int number = 0, int x = 0, int y = 0, double angle = 0): number(number), x(x), y(y), angle(angle) {}

    int number;
    int x, y;
    double angle;
};

pumpkin min_pumpkin(1, INT_MAX, INT_MAX);
vector<pumpkin> p;

bool operator < (pumpkin left, pumpkin right) {
    if (left.angle == right.angle) {
        if (left.y == right.y) {
            return left.x > right.x;
        }
        return left.y < right.y;
    }

    return left.angle > right.angle;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        p.emplace_back(pumpkin(i + 1, x, y));
        if (min_pumpkin.x > x || (min_pumpkin.y > y && min_pumpkin.x == x)) {
            min_pumpkin = pumpkin(i + 1, x, y);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i + 1 != min_pumpkin.number) {
            if (min_pumpkin.x == p[i].x) {
                p[i].angle = DOUBLE_MAX;
            } else {
                p[i].angle = (p[i].y - min_pumpkin.y) / (double) (p[i].x - min_pumpkin.x);
            }
        } else {
            p[i].angle = DOUBLE_MAX;
        }
    }

    sort(p.begin(), p.end());

    cout << n << endl;

    int counter = 0;
    while (p[counter].number != 1) {
        counter++;
    }

    for (int i = counter; i < n; ++i) {
        cout << p[i].number << endl;
    }
    for (int i = 0; i < counter; ++i) {
        cout << p[i].number << endl;
    }
}