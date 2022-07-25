#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

#define MAX 1001
int n, m;
string s;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    queue<pair<int, int>> wall;
    q.push({x, y});
    visit[x][y] = true;
    int cnt = 1;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if (map[nx][ny] == 0 && !visit[nx][ny]) {
                visit[nx][ny] = true;
                q.push({nx, ny});
                cnt++;
            } else if (map[nx][ny] != 0 && !visit[nx][ny]) {
                visit[nx][ny] = true;
                wall.push({nx, ny});
            }
        }
    }

    while (!wall.empty()) { //만난 벽들에게 cnt 더해주고 visit 해제
        int wx = wall.front().first;
        int wy = wall.front().second;

        map[wx][wy] += cnt;
        visit[wx][wy] = false;
        wall.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s.at(j) - '0';//char -> int
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0 && !visit[i][j]) {
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j] % 10;
        }
        cout << "\n";
    }

    return 0;
}