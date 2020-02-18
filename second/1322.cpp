#include <iostream>
#include <string>
#include <vector>

//http://neerc.ifmo.ru/wiki/index.php?title=%D0%9F%D1%80%D0%B5%D0%BE%D0%B1%D1%80%D0%B0%D0%B7%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5_%D0%91%D0%B0%D1%80%D1%80%D0%BE%D1%83%D0%B7%D0%B0-%D0%A3%D0%B8%D0%BB%D0%B5%D1%80%D0%B0

using namespace std;

string reverseBWT(int n, int m, int k, string s) {
    vector<int> count(m, 0);
    vector<int> t(n, 0);
    string answer(n, '0');

    for (int i = 0; i < n; ++i) {
        count[s[i] - 'A']++;
    }

    int sum = 0;

    for (int i = 0; i < m; ++i) {
        sum += count[i];
        count[i] = sum - count[i];
    }

    for (int i = 0; i < n; ++i) {
        t[count[s[i] - 'A']] = i;
        count[s[i] - 'A']++;
    }

    int j = t[k-1];

    for (int i = 0; i < n; ++i) {
        answer[i] = s[j];
        j = t[j];
    }

    return answer;
}

int main(int argc, const char * argv[]) {
    int k;
    cin >> k;

    string input;
    cin >> input;

    cout << reverseBWT(input.length(), 64, k, input);

    return 0;
}