#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    int n;
    cin >> n;

    int localmax = 0;
    int globalmax = 0;

    int current;

    for (int i = 0; i < n; ++i) {
        cin >> current;
        localmax += current;

        if (localmax < 0) {
            localmax = 0;
        }

        if (localmax > globalmax) {
            globalmax = localmax;
        }
    }

    cout << globalmax;

    return 0;
}