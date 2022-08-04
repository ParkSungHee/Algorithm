#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int v1, v2;
    int cost;
};

#define MAX 1001
int n, m, x, y;
int total_cost = 0;
vector<Edge> computer;
vector<pair<int, int>> v;
int par[MAX];

bool cmp(Edge &e1, Edge &e2) {
    if (e1.cost == e2.cost) {
        if (e1.v1 == e2.v1) {
            return e1.v2 < e2.v2;
        }
        return e1.v1 < e2.v1;
    }
    return e1.cost < e2.cost;
}

int Find(int v1) {
    if (v1 == par[v1])
        return v1;
    return par[v1] = Find(par[v1]);
}

bool Union(int v1, int v2) {
    v1 = Find(v1);
    v2 = Find(v2);

    if (v1 != v2) {
        par[v1] = v2;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    while (m--) {
        cin >> x >> y;
        Union(x, y);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x;
            if (i >= j) {
                continue;
            }
            computer.push_back({i, j, x});
        }
    }

    sort(computer.begin(), computer.end(), cmp);

    for (auto &c: computer) {
        int v1 = c.v1;
        int v2 = c.v2;
        int cost = c.cost;

        if (v1 == 1 || v2 == 1) {
            continue;
        }

        if (Union(v1, v2)) {
            v.emplace_back(v1, v2);
            total_cost += cost;
        }
    }
    if (v.empty()) {
        cout << 0 << " " << 0 << "\n";
    } else {
        cout << total_cost << " " << v.size() << "\n";
        for (auto &ss: v) {
            cout << ss.second << " " << ss.first << "\n";
        }
    }

    return 0;
}