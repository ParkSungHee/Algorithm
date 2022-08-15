#include <iostream>
#include <vector>
using namespace std;

#define INF 100000000
#define MAX 101
int n, m, r, a, b, c;
int dist[MAX][MAX];
vector<int> items;
int maxRes = 0;

int main() {
    cin >> n >> m >> r;

    items.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> items[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;
                dist[j][i] = 0;
            } else {
                dist[i][j] = INF;
                dist[j][i] = INF;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        cin >> a >> b >> c;
        if (dist[a][b] > c) {
            dist[a][b] = c;
            dist[b][a] = c;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == INF || dist[k][j] == INF) {
                    continue;
                }
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    dist[j][i] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int sum = 0;

        for (int j = 1; j <= n; j++) {
            if (dist[i][j] <= m) {
                sum += items[j];
            }
        }
        if (sum > maxRes) {
            maxRes = sum;
        }
    }

    cout << maxRes;
    return 0;
}
