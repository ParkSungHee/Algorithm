#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1001
#define INF 987654321

vector<pair<int, int>> map[MAX];
int d[MAX], par[MAX];
int n, m, a, b, t, result = 0, minRes = 0;
bool first = true;

void dijkstra(int x, int y) {
    for (int j = 0; j <= n; j++)
        d[j] = INF;

    priority_queue<pair<int, int> > pq;
    d[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if (distance > d[current])
            continue;

        for (auto &i: map[current]) {
            int next = i.first;
            int nextDistance = distance + i.second;

            if ((x == current && y == next) || (y == current && x == next))
                continue;

            if (d[next] > nextDistance) {
                if (first)
                    par[next] = current;
                d[next] = nextDistance;
                pq.push({-nextDistance, next});
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while (m--) {
        cin >> a >> b >> t;
        map[a].emplace_back(b, t);
        map[b].emplace_back(a, t);
    }

    par[1] = 1;
    dijkstra(0, 0);
    first = false;
    minRes = d[n];

    for (int p = n; p != par[p]; p = par[p]) {
        dijkstra(p, par[p]);

        if (d[n] == INF) {
            result = -1;
            break;
        }
        result = max(result, d[n] - minRes);
    }

    cout << result << "\n";
    return 0;
}