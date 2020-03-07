#include <stdio.h>
#include <memory>
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>
#include <limits>

const int inf = std::numeric_limits<int>::max()/2;
const int width = 10;
const int maxn = 50000;

long long pw[width];
int cost[width];

struct Node {
    std::vector<std::pair<int, Node*>> v;
    Node* parent;
    int d;
    bool visited;
} nodes[maxn];

std::unordered_map<long long, Node*> m;

int getDigit(long long num, int i) {
    return num/pw[i]%10;
}

long long setDigit(long long num, int i, int d) {
    return num - ((long long) getDigit(num, i))*pw[i] + d*pw[i];
}

int matchPrefix(long long num1, long long num2) {
    int matched = 0;
    for(int i = width-1; i >= 0; i--){
        if(getDigit(num1, i) == getDigit(num2, i))
            matched++;
        else
            break;
    }
    return matched;
}

void add(long long num, int id) {
    std::vector<std::pair<int, Node*>> v;
    for(int i = 0; i < width; i++) {
        for(int d = 0; d < 10; d++) {
            auto num2 = setDigit(num, i, d);
            auto it = m.find(num2);
            if(it != m.end()) {
                int c = cost[matchPrefix(num, num2)];
                v.push_back( { c, (*it).second } );
            }
        }
    }
    for(int i = 0; i < width; i++) {
        for(int j = i+1; j < width; j++) {
            int di = getDigit(num, i);
            int dj = getDigit(num, j);
            auto num2 = setDigit(setDigit(num, j, di), i, dj);
            auto it = m.find(num2);
            if(it != m.end()){
                int c = cost[matchPrefix(num, num2)];
                v.push_back( { c, (*it).second } );
            }
        }
    }
    m[num] = &nodes[id];
    for(auto p : v) {
        p.second->v.push_back( { p.first, &nodes[id] } );
        nodes[id].v.push_back( { p.first, p.second } );
    }
}

void search(Node* start, int N) // Dijkstra
{
    using pin = std::pair<int, Node*>;
    std::priority_queue<pin, std::vector<pin>, std::greater<pin>> q;

    for(int i = 0; i < N; i++) {
        nodes[i].d = inf, nodes[i].visited = false;
    }
    start->d = 0;

    q.push( { 0, start } );
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        auto node = p.second;
        if(node->visited)
            continue;
        node->visited = true;
        for(auto it = node->v.begin(); it < node->v.end(); it++){
            auto n = (*it).second;
            int cost = (*it).first;
            if(!n->visited && n->d > node->d + cost){
                n->parent = node;
                n->d = node->d + cost;
                q.push( { n->d, n });
            }
        }
    }
}

int main() {
    long long b = 1;
    for(int i = 0; i < width; i++) {
        pw[i] = b, b *= 10;
    }

    int n;
    scanf("%d", &n);
    for(int i = 0; i < width; i++) {
        scanf("%d", cost + i);
    }

    for(int i = 0; i < n; i++) {
        long long num;
        scanf("%lld", &num);
        add(num, i);
    }
    std::vector<Node*> result;
    search(&nodes[0], n);
    if(!nodes[n-1].visited) {
        printf("-1");
        return 0;
    }
    printf("%d\n", nodes[n-1].d);
    for(Node* node = &nodes[n-1]; node; node = node->parent) {
        result.push_back(node);
    }
    printf("%d\n", result.size());
    for(auto it = result.rbegin(); it < result.rend(); it++) {
        printf("%d ", 1 + (*it - nodes));
    }
}