#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> tree[10001];
bool visit[10001];
int n, maxNode, maxDist = 0;

void dfs(int node, int weight) {
    if (visit[node])
        return;

    visit[node] = true;
    if (maxDist < weight) {
        maxDist = weight;
        maxNode = node;
    }

    for (auto x : tree[node]) {
        int nextNode = x.first;
        int nextWeight = x.second + weight;

        dfs(nextNode, nextWeight);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    int parent, child, weight;
    for (int i = 0; i < n - 1; i++) {
        cin >> parent >> child >> weight;

        tree[parent].emplace_back(child, weight);
        tree[child].emplace_back(parent, weight);
    }

    dfs(1, 0);

    memset(visit, false, sizeof(visit));
    maxDist = 0;

    dfs(maxNode, 0);

    cout << maxDist;
    return 0;
}