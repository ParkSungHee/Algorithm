#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 1001
int n, m, k;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int BFS(int mid) {
    memset(visit, 0, sizeof(visit));
    int cnt = 0;
    queue<pair<int, int>> q;

    for (int i = 1; i <= n; i++) {
        if (map[i][1] <= mid) {
            q.push({i, 1});
            visit[i][1] = true;
        }
        if (m > 1 && map[i][m] <= mid) {
            q.push({i, m});
            visit[i][m] = true;
        }
    }

    for (int i = 2; i <= m - 1; i++) {
        if (map[1][i] <= mid) {
            q.push({1, i});
            visit[1][i] = true;
        }
    }

    while (!q.empty()) {
        cnt++;
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;

            if (!visit[nx][ny] && map[nx][ny] <= mid) {
                q.push({nx, ny});
                visit[nx][ny] = true;
            }
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m >> k;

    int maxR = 0, minR = 1000000;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            maxR = max(maxR, map[i][j]);
            minR = min(minR, map[i][j]);
        }
    }

    int left = minR, right = maxR;
    while (left < right) {
        int mid = (left + right) / 2;
        if (BFS(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }

    cout << left;
    return 0;
}