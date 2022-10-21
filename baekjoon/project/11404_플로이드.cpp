#include <iostream>
using namespace std;

#define INF 1000000001 //정점 100 x 비용 10만
#define MAX 102
int dist[MAX][MAX];
int n, m, a, b, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }

    while (m--) {
        cin >> a >> b >> c;
        if (dist[a][b] > c) {
            dist[a][b] = c;
        }
    }

    for (int k = 1; k <= n; k++) { //거쳐가는게 중심
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == INF || dist[k][j] == INF) {
                    continue;
                }

                // i에서 k로 가는비용 + k에서 j로 가는비용 vs i에서 j로 가는 비용
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF || i == j) {
                cout << "0 ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
//4 7
//1 2 4
//1 4 6
//2 1 3
//2 3 7
//3 1 5
//3 4 4
//4 3 2

//결과
//0 4 8 6
//3 0 7 9
//5 9 0 4
//7 11 2 0