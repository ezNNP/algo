#include <iostream>
#include <vector>
#include <climits>

struct Edge {
    explicit Edge(int a = 0, int b = 0, int cost = 0): a(a), b(b), cost(cost) {}
    int a;
    int b;
    int cost;
};

using namespace std;

int main(int argc, const char * argv[]) {
    //https://e-maxx.ru/algo/ford_bellman
    int n, m;
    scanf("%d %d", &n, &m);
    vector<Edge> edges(m);
    vector<long long> costs(n, LONG_LONG_MAX);
    for (int i = 0; i < m; ++i) {
        int a, b, cost;
        scanf("%d %d %d", &a, &b, &cost);
        edges[i] = Edge(--a, --b, -cost);
    }

    int s, f;
    scanf("%d %d", &s, &f);

    costs[--s] = 0;

    bool any = true;

    while (any) {
        any = false;
        for (int i = 0; i < m; ++i) {
            if (costs[edges[i].a] < LONG_LONG_MAX) {
                if (costs[edges[i].b] > costs[edges[i].a] + edges[i].cost) {
                    costs[edges[i].b] = costs[edges[i].a] + edges[i].cost;
                    any = true;
                }
            }
        }
    }

    if (costs[--f] != LONG_LONG_MAX) {
        cout << -costs[f];
    } else {
        cout << "No solution";
    }

    return 0;
}