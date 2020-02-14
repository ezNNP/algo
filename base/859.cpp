#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length())
            return false;

        if (A == B) {
            int c[26];

            for (int i = 0; i < 26; ++i) {
                c[i] = 0;
            }

            for (int i = 0; i < A.length(); ++i) {
                c[A[i] - 'a']++;
            }

            for (int i = 0; i < 26; ++i) {
                if (c[i] > 1) {
                    return true;
                }
            }
            return false;
        } else {
            int first = -1;
            int second = -1;
            for (int i = 0; i < A.length(); ++i) {
                if (A[i] != B[i]) {
                    if (first == -1) {
                        first = i;
                    } else if (second == -1) {
                        second = i;
                    } else {
                        return false;
                    }
                }
            }
            return first != -1 && second != -1 && A[first] == B[second] && A[second] == B[first];
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution a;
    cout << (a.buddyStrings("ab", "ba") ? "True" : "False") << endl;
    cout << (a.buddyStrings("ab", "ab") ? "True" : "False") << endl;
    cout << (a.buddyStrings("aa", "aa") ? "True" : "False") << endl;
    cout << (a.buddyStrings("aaaabc", "aaaacb") ? "True" : "False") << endl;


    return 0;
}
