#include <iostream>
#include <vector>

using namespace std;

struct Sign {
    Sign(int id = 0, int frequency = 0) : id(id), frequency(frequency) {}

    int id;
    int frequency;
};

bool operator<(Sign left, Sign right) {
    return left.frequency < right.frequency;
}

bool operator>(Sign left, Sign right) {
    return left.frequency > right.frequency;
}

int main(int argc, const char * argv[]) {

    int k;
    cin >> k;


    vector<Sign> signs;

    for (int i = 0; i < k; ++i) {
        int frequency;
        cin >> frequency;
        signs.emplace_back(i+1, frequency);
    }

    while (true) {
        Sign max1(-1, 0);
        Sign max2(-1, 0);

        for (int i = 0; i < k; ++i) {
            if (signs[i] > max1) {
                if (max1 > max2) {
                    max2 = max1;
                }
                max1 = signs[i];
            } else if (signs[i] > max2) {
                max2 = signs[i];
            }
        }

        if (max2.id == -1) {
            if (max1.id != -1) {
                for (int i = 0; i < signs[max1.id - 1].frequency; ++i) {
                    cout << max1.id << " ";
                }
            }
            break;
        }
        signs[max1.id - 1].frequency--;
        signs[max2.id - 1].frequency--;
        cout << max1.id << " " << max2.id << " ";
    }

    return 0;
}