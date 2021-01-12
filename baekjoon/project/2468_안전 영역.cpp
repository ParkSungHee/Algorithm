#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
#include <string.h>

using namespace std;
int N, M = -1;
int depth[101][101];
int visit[101][101];
int pos[4][2] = { {-1,0},
                  {1,0},
                  {0,-1},
                  {0,1} };	//╩С го аб ©Л
int cnt = 0;
priority_queue < int > pq;

void bfs(int limit, int y, int x) {
    visit[y][x] = 1;
    queue < pair < int, int > > q;
    q.push(make_pair(y, x));
    while (!q.empty()) {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newy = ny + pos[i][1];
            int newx = nx + pos[i][0];
            if (newy > N || newy <= 0 || newx > N || newx <= 0)
                continue;
            if (visit[newy][newx])
                continue;
            if (depth[newy][newx] > limit) {
                visit[newy][newx] = 1;
                q.push(make_pair(newy, newx));
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> depth[i][j];
            M = max(depth[i][j], M);
        }
    }
    for (int i = 1; i < M; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (visit[j][k] == 0 && depth[j][k] > i) {
                    bfs(i, j, k);
                    cnt++;
                }
            }
        }
        pq.push(cnt);
        memset(visit, 0, sizeof(visit));
        cnt = 0;
    }
    pq.push(1);
    cout << pq.top() << endl;
}