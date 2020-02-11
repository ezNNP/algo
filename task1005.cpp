#include <algorithm>
#include <iostream>

#define MAX_INT 2147483647;

using namespace std;

void rec_division(int iteration, int sum1, int sum2, const int * arr);

int n;
int minimum = MAX_INT;

int main(int argc, const char * argv[]) {
    cin >> n;

    int * arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    rec_division(0, 0, 0, arr);

    cout << minimum;

    return 0;
}

void rec_division(int iteration, int sum1, int sum2, const int * arr) {
    if (iteration == n) {
        minimum = min(minimum, abs(sum1 - sum2));
    } else {
        rec_division(iteration + 1, sum1 + arr[iteration], sum2, arr);
        rec_division(iteration + 1, sum1, sum2 + arr[iteration], arr);
    }
}