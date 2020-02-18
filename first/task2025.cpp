// титульник, постановка задачи, краткое словестное описание решения,
// блок-схема реализованного алгоритма, текст решения с комментариями

#include <iostream>
#include <vector>

using namespace std;

void solve_and_print(int n, int k);

int main(int argc, const char * argv[]) {
    int T; // количество тестов
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int n, k;
        cin >> n >> k;
        solve_and_print(n, k);
    }

    return 0;
}

void solve_and_print(int n, int k) {
    int nn; // (nn > n) & (nn % k == 0)
    if (n % k == 0) {
        nn = n;
    } else {
        nn = n + k - (n % k);
    }
    int* teams = new int[10000];
    for (int i = 0; i < k; ++i) {
        teams[i] = nn / k;
    }
    int dec_team_pointer = 0;
    while (nn > n) { // пока nn > n будем убирать из каждый команды по одному человеку
        teams[dec_team_pointer++]--;
        nn--;
        if (dec_team_pointer == k) {
            dec_team_pointer = 0;
        }
    }

    long long result = 0; // считаем результат
    for (int i = 0; i < k - 1; ++i) {
        for (int j = i+1; j < k; ++j) {
            result += teams[i] * teams[j];
        }
    }

    delete [] teams;

    cout << result << endl;
}