#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define MAX 1001
int n, m, k;
string s;
char map[MAX][MAX];
int dist[MAX][MAX][11]; //visit 역할
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

typedef struct Position {
    int x, y;
    int wall; //누적되어 부쉰 갯수
} Pos;

int bfs(int X, int Y) {
    queue<Pos> q;
    q.push({X, Y, 0}); //처음 위치, 깬벽 X
    dist[X][Y][0] = 1; //안 깬 상태로 거리 1

    while (!q.empty()) {
        auto cur = q.front();
        int wall = cur.wall;
        q.pop();

        //해당 위치에 도달했으면
        if (cur.x == n - 1 && cur.y == m - 1) {
            return dist[cur.x][cur.y][wall];
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            //벽으로 막혀있는데 아직 벽 깰 수 있고 방문 안했다면
            if (map[nx][ny] == '1' && wall < k && dist[nx][ny][wall + 1] == 0) {
                q.push({nx, ny, wall + 1});
                dist[nx][ny][wall + 1] = dist[cur.x][cur.y][wall] + 1;
            }
                //벽이 없고 현재 상태에서 방문하지 않은 곳이라면
            else if (map[nx][ny] == '0' && dist[nx][ny][wall] == 0) {
                q.push({nx, ny, wall});
                dist[nx][ny][wall] = dist[cur.x][cur.y][wall] + 1;
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s.at(j);
        }
    }

    int result = bfs(0, 0);
    cout << result;
    return 0;
}