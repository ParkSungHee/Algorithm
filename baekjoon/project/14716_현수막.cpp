#include <iostream>
using namespace std;

#define MAX 251
int graph[MAX][MAX];
bool visit[MAX][MAX];
int m, n;
int dx[8] = {0, 0, 1, -1, -1, 1, -1, 1};
int dy[8] = {-1, 1, 0, 0, -1, 1, 1, -1};

void DFS(int y, int x) {
    visit[y][x] = true;

    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n) {
            continue;
        }
        if (graph[ny][nx] == 1 && !visit[ny][nx]) {
            DFS(ny, nx);
        }
    }
}

int main() {
    int result = 0;

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visit[i][j] || graph[i][j] == 0) {
                continue;
            }
            DFS(i, j);
            result++;
        }
    }
    cout << result;
    return 0;
}