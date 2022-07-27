#include <iostream>
#include <algorithm>
using namespace std;

int map[1001][1001], dp[502][502];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n;

int dfs(int x, int y) {
    if (dp[x][y] != 0) {
        return dp[x][y];
    }

    int max_dist = 0;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
            continue;
        }

        if (map[nx][ny] <= map[x][y]) {
            continue;
        }

        max_dist = max(max_dist, dfs(nx, ny));
    }

    return dp[x][y] = max_dist + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int maxSize = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            maxSize = max(dfs(i, j), maxSize);
        }
    }

    cout << maxSize;

    return 0;
}