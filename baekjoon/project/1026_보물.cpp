#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dist[1001][1001][1001];
int map[1001][1001];
bool visit[1001];
int n, m, v;

void BFS(int v) {
    queue<pair<int, pair<int, int>>> q; //cnt, x, y
    dist[0][1][1] = 1;

    visit[v] = true;

    while (!q.empty()) {
        int i = q.front().

        for (int i = 1; i <= n; i++) {
            if (map[v][i] == 0 || visit[i])
                continue;
            q.push(i);
            visit[i] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> n >> m >> v;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[b][a];
        }
    }
    BFS(v);
    return 0;
}