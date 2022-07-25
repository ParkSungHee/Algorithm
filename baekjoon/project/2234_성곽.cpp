#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int map[100][100] = {0,};
bool visit[100][100];
int n, m, maxRoom = 0, roomCnt = 0, maxBreak = 0;

// x가 행, y가 열을 의미
//  		  x-1, y
//  x, y-1     x, y     x, y+1
//   		  x+1, y
int posx[4] = {0, -1, 0, 1};
int posy[4] = {-1, 0, 1, 0};
//벽
//서:1, 북:2, 동:4, 남:8

int bfs(int x, int y) {
    int room = 0;
    queue<pair<int, int>> q;
    visit[x][y] = true;
    q.push({x, y}); //시작 정점

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        room += 1;

        for (int dir = 0; dir < 4; dir++) {
            if (map[cur.first][cur.second] & (1 << dir)) { //벽이면
                continue;
            }

            //동서남북 보기
            int nx = cur.first + posx[dir];
            int ny = cur.second + posy[dir];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) //범위 초과한 경우
                continue;
            if (visit[nx][ny]) //방문했으면
                continue;
            visit[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return room;
}

void breakWall(int x, int y) {
    for (int wall = 1; wall <= 8; wall *= 2) {
        if ((map[x][y] & wall) == wall) { //벽이면
            map[x][y] -= wall; //벽없애기

            int roomSize = bfs(x, y);
            maxBreak = max(maxBreak, roomSize);

            map[x][y] += wall; //원상복구
        }
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j]; //각 방의 상태가 주어짐
        }
    }
    //11 : 1+2+8 (서,북,남)
    //6 : 2+4 (북,동)

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j]) {
                int roomSize = bfs(i, j);
                roomCnt++;
                maxRoom = max(maxRoom, roomSize);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            memset(visit, 0, sizeof(visit));
            breakWall(i, j);
        }
    }

    cout << roomCnt << "\n" << maxRoom << "\n" << maxBreak;

    return 0;
}