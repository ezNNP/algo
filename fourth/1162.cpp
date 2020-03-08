#include <iostream>
#include <vector>

#define DOUBLE_MAX std::numeric_limits<double>::max()

using namespace std;

struct edge {
    edge(int a, int b, double rab, double cab): a(a), b(b), rab(rab), cab(cab) {}

    int a, b;
    double rab, cab;
};

int main(int argc, const char * argv[]) {
    int n, m, s;
    double v;
    cin >> n >> m >> s >> v;
    vector<edge> e;
    for (int i = 0; i < m; ++i) {
        int from, to;
        double rab, cab, rba, cba;
        cin >> from >> to >> rab >> cab >> rba >> cba;
        e.emplace_back(--from, --to, rab, cab);
        e.emplace_back(to, from, rba, cba);
    }

    vector<double> dist(n, 0);
    dist[s-1] = v;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < e.size(); ++j) {
            dist[e[j].b] = max(dist[e[j].b], (dist[e[j].a] - e[j].cab) * e[j].rab);
        }
    }

    for (int i = 0; i < e.size(); ++i) {
        if ((dist[e[i].a] - e[i].cab) * e[i].rab > dist[e[i].b] + 0.00001) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;


}