#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> result;
        for (auto i = A.begin(); i != A.end(); ++i) {
            if (*i % 2 == 0) {
                result.insert(result.begin(), *i);
            } else {
                result.push_back(*i);
            }
        }

        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> test{3, 1, 2, 4};
    Solution solution;
    vector<int> result = solution.sortArrayByParity(test);
    for (auto i = result.begin(); i != result.end(); ++i) {
        cout << *i << " ";
    }

    return 0;
}