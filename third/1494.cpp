#include <iostream>
#include <stack>

using namespace std;

int main(int  argc, const char * argv[]) {
    int n;
    cin >> n;
    stack<int> arr;
    bool cheater = false;
    int last, current;
    last = 0;
    for (int i = 0; i < n; ++i) {
        cin >> current;
        for (int j = last+1; j <= current; ++j) {
            arr.push(j);
        }
        last = last > current ? last : current;
        if (arr.top() == current) {
            arr.pop();
        } else {
            cheater = true;
            break;
        }
    }
    if (cheater) {
        cout << "Cheater";
    } else {
        cout << "Not a proof";
    }
    return 0;
}