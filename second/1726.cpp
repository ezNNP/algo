#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    long long n;
    cin >> n;

    long long answer = 0;
    vector<long long> x;
    vector<long long> y;
    x.emplace_back(-1);
    y.emplace_back(-1);

    for (int i = 0; i < n; ++i) {
        long long cx, cy;
        cin >> cx >> cy;
        x.emplace_back(cx);
        y.emplace_back(cy);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for (int i = 0; i < n; ++i) {
        answer += (x[i+1]-x[i] + y[i+1]-y[i]) * i * (n-i) * 2;
    }

    answer /= (n * (n-1));

    cout << answer;

    return 0;
}