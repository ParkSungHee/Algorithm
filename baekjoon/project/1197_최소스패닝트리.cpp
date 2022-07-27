#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10001
int par[MAX];
int res = 0, cnt = 0;

struct Edge {
    int v1, v2;
    int cost;
};

bool cmp(const Edge &edge1, const Edge &edge2) {
    if (edge1.cost == edge2.cost) {
        if (edge1.v1 == edge2.v1) {
            return edge1.v2 < edge2.v2;
        }
        return edge1.v1 < edge2.v1;
    }
    return edge1.cost < edge2.cost;
}

int Find(int v) {
    if (v == par[v]) {
        return v;
    }
    return par[v] = Find(par[v]);
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v, e, a, b, c;
    vector<Edge> edge;

    cin >> v >> e;

    for (int i = 1; i <= v; i++) {
        par[i] = i;
    }

    while (e--) {
        cin >> a >> b >> c;
        edge.push_back({a, b, c});
    }
    sort(edge.begin(), edge.end(), cmp);

    for (auto &ed: edge) {
        int v1 = ed.v1;
        int v2 = ed.v2;
        int cost = ed.cost;

        if (Union(v1, v2)) {
            res += cost;
            cnt += 1;

            if (cnt == v - 1) {
                break;
            }
        }
    }

    cout << res;
    return 0;
}