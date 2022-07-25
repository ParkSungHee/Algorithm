#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int map[100][100] = {0,};
bool visit[100][100];
int n, m, maxRoom = 0, roomCnt = 0, maxBreak = 0;

// x�� ��, y�� ���� �ǹ�
//  		  x-1, y
//  x, y-1     x, y     x, y+1
//   		  x+1, y
int posx[4] = {0, -1, 0, 1};
int posy[4] = {-1, 0, 1, 0};
//��
//��:1, ��:2, ��:4, ��:8

int bfs(int x, int y) {
    int room = 0;
    queue<pair<int, int>> q;
    visit[x][y] = true;
    q.push({x, y}); //���� ����

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        room += 1;

        for (int dir = 0; dir < 4; dir++) {
            if (map[cur.first][cur.second] & (1 << dir)) { //���̸�
                continue;
            }

            //�������� ����
            int nx = cur.first + posx[dir];
            int ny = cur.second + posy[dir];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) //���� �ʰ��� ���
                continue;
            if (visit[nx][ny]) //�湮������
                continue;
            visit[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return room;
}

void breakWall(int x, int y) {
    for (int wall = 1; wall <= 8; wall *= 2) {
        if ((map[x][y] & wall) == wall) { //���̸�
            map[x][y] -= wall; //�����ֱ�

            int roomSize = bfs(x, y);
            maxBreak = max(maxBreak, roomSize);

            map[x][y] += wall; //���󺹱�
        }
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j]; //�� ���� ���°� �־���
        }
    }
    //11 : 1+2+8 (��,��,��)
    //6 : 2+4 (��,��)

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