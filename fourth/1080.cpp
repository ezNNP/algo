#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {

    int n;

    cin >> n;

    vector<vector<int>> g;
    vector<int> colors (n, -1);
    vector<int> q(n);

    int input;

    for (int i = 0; i < n; ++i) {
        vector<int> current;
        cin >> input;

        while (input != 0) {
            current.push_back(--input);
            cin >> input;
        }
        g.push_back(current);
    }

    //FIXME: create undirectional graph with duplicates
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            g[g[i][j]].push_back(i);
        }
    }

    for (int st = 0; st < n; ++st) {
        if (colors[st] == -1) {
            int h=0, t=0;
            q[t++] = st;
            colors[st] = 0;
            while (h<t) {
                int v = q[h++];
                for (size_t i = 0; i < g[v].size(); ++i) {
                    int to = g[v][i];
                    if (colors[to] == -1) {
                        colors[to] = !colors[v], q[t++] = to;
                    } else if (colors[to] == colors[v]) {
                        cout << "-1";
                        return 0;
                    }
                }
            }
        }
    }

    for (int color : colors) {
        cout << color;
    }

    return 0;
}