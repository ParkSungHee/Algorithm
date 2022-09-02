#include <iostream>
#include <vector>
using namespace std;

#define MAX 500
int n;
int map[MAX][MAX];
int result = 0;

int dx[] = {0, 0, 1, -1}; //오른쪽 왼쪽 아래 위
int dy[] = {1, -1, 0, 0};
int ddx[4][10] = {{-1, 1, -1, 1,  -1, 1,  -2, 2,  0,  0},
                  {-1, 1, -1, 1,  -1, 1,  -2, 2,  0,  0},
                  {0,  0, 1,  1,  2,  2,  1,  1,  3,  2},
                  {0,  0, -1, -1, -2, -2, -1, -1, -3, -2}};
int ddy[4][10] = {{0,  0, 1,  1,  2,  2,  1,  1,  3,  2},
                  {0,  0, -1, -1, -2, -2, -1, -1, -3, -2},
                  {-1, 1, -1, 1,  -1, 1,  -2, 2,  0,  0},
                  {-1, 1, -1, 1,  -1, 1,  -2, 2,  0,  0}};
int per[9] = {1, 1, 7, 7, 10, 10, 2, 2, 5};


void spread(int x, int y, int dir) { // dir에 따라 spread 다르게 뿌리기
    //y로 이동
    int xx = x + dx[dir];
    int yy = y + dy[dir];

    int tmp = map[xx][yy];
    int remain = tmp;

    if (tmp == 0) {
        return;
    }

    //적혀있는 비율
    for (int i = 0; i < 9; i++) {
        int p = per[i];
        int nx = x + ddx[dir][i];
        int ny = y + ddy[dir][i];
        int cal = (tmp * p) / 100;

        if (nx < 1 || nx > n || ny < 1 || ny > n) {
            result += cal;
        } else {
            map[nx][ny] += cal;
        }

        remain -= cal;
    }

    //알파라서 남은거 따로 계산
    int nx = x + ddx[dir][9];
    int ny = y + ddy[dir][9];

    if (nx < 1 || nx > n || ny < 1 || ny > n) {
        result += remain;
    } else {
        map[nx][ny] += remain;
    }

    map[xx][yy] = 0;
}

int changeDir(int dir) {
    if (dir == 0)return 3;
    if (dir == 1)return 2;
    if (dir == 2)return 0;
    if (dir == 3)return 1;
}

void magic() {
    int x = (n + 1) / 2, y = (n + 1) / 2;
    int dir = 1;
    int mov = 1;

    while (true) {
        if (mov == n) {
            for (int j = 0; j < mov; j++) {
                spread(x, y, dir);
                x += dx[dir];
                y += dy[dir];
            }
            break;
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < mov; j++) {
                spread(x, y, dir);
                x += dx[dir];
                y += dy[dir];
            }
            dir = changeDir(dir);
        }
        mov++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    magic();

    cout << result;
    return 0;
}