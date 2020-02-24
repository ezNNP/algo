#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

struct Point {
    Point(long id, long long x, long long y): id(id), x(x), y(y) {}

    long id;
    long long x;
    long long y;
    long double tg;
};

bool operator < (Point left, Point right) {
    return left.tg < right.tg;
}

bool operator > (Point left, Point right) {
    return (left.tg != right.tg) && (left > right);
}

int main(int argc, const char * argv[]) {
    long n;
    cin >> n;

    vector<Point> points;

    Point min_point(-1, LLONG_MAX, LLONG_MAX);

    for (long i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        Point current(i+1, x, y);
        points.emplace_back(current);
        if (min_point.x > x || (min_point.y > y && min_point.x == x)) {
            min_point = current;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i + 1 != min_point.id) {
            if (points[i].x == min_point.x) {
                points[i].tg = LLONG_MAX;
            } else {
                points[i].tg = (points[i].y - min_point.y) / (long double) (points[i].x - min_point.x);
            }
        } else {
            points[i].tg = LLONG_MIN;
        }
    }

    sort(points.begin(), points.end());

    cout << min_point.id << " " << points[n / 2].id;

    return 0;
}