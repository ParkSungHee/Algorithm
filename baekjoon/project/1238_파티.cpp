#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, x;
int a, b, c;
int INF = 10000000;
vector<pair<int, int>> v[1001];
int d[1001], res[1001];

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();

        if (d[current] < distance)
            continue;

        for (auto i: v[current]) {
            int next = i.first;
            int nextDistance = i.second + distance;

            if (nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push({next, -nextDistance});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x;

    while (m--) {
        cin >> a >> b >> c;

        v[a].push_back({b, c});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[j] = INF;
        }
        dijkstra(i); // i 출발
        res[i] = d[x]; // x 도착
    }
    for (int j = 1; j <= n; j++) {
        d[j] = INF;
    }
    dijkstra(x);
    for (int j = 1; j <= n; j++) {
        res[j] += d[j];
    }
    sort(res + 1, res + 1 + n); //최대값 찾기

    cout << res[n];

    return 0;
}