#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
vector<int> p (n);

int dsu_get (int v) {
    return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int a, int b) {
    a = dsu_get (a);
    b = dsu_get (b);
    if (rand() & 1)
        swap (a, b);
    if (a != b)
        p[a] = b;
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    vector < pair < int, pair<int,int> > > g;
    for (int i = 0; i < m; ++i) {
        long a, b, cost;
        cin >> a >> b >> cost;
        pair<int,int> edges;
        edges.first = --a;
        edges.second = --b;
        pair<int, pair<int, int>> full;
        full.first = cost;
        full.second = edges;
        g.emplace_back(full);
    }

    int cost = 0;
    vector < pair<int,int> > res;
    sort (g.begin(), g.end());
    p.resize (n);
    for (int i=0; i<n; ++i)
        p[i] = i;
    for (int i=0; i<m; ++i) {
        int a = g[i].second.first,  b = g[i].second.second,  l = g[i].first;
        if (dsu_get(a) != dsu_get(b)) {
            cost = cost > l ? cost : l;
            res.push_back (g[i].second);
            dsu_unite (a, b);
        }
    }
    cout << cost << endl;
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
    }

    return 0;
}