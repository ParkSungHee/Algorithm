#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct types {
    int x, y, z;
};

int M, N, H; //가로 세로 높이
int map[101][101][101];
int visit[101][101][101];
int posx[6] = { -1,1,0,0,0,0 };
int posy[6] = { 0,0, -1,1,0,0 };
int posz[6] = { 0,0,0,0,-1,1 };
queue<types> q;

int main(void) {
    int count = 0;
    cin >> M >> N >> H;

    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                cin >> map[n][m][h];
                if (map[n][m][h] == 1) {
                    q.push({ n, m, h });
                }
                else if (map[n][m][h] == 0)
                    visit[n][m][h] = -1;
            }
        }
    }

    if (q.empty()) {
        cout << "-1";
        return 0;
    }

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int tempx = v.x + posx[i];
            int tempy = v.y + posy[i];
            int tempz = v.z + posz[i];

            if (tempx >= 0 && tempy >= 0 && tempz >= 0 && tempx < N && tempy < M && tempz < H)
                if (visit[tempx][tempy][tempz] < 0) {
                    q.push({ tempx, tempy, tempz });
                    visit[tempx][tempy][tempz] = visit[v.x][v.y][v.z] + 1;
                }
        }
    }

    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (visit[n][m][h] == -1) {
                    cout << "-1";
                    return 0;
                }

                count = max(count, visit[n][m][h]);
            }
        }
    }
    cout << count;
    return 0;

}