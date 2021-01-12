#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define max 10
using namespace std;

int N, M, result = 0;
int map[max][max];
int temp[max][max];
int visit[max][max] = { 0, };

void ary_cp(void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            temp[i][j] = map[i][j];
        }
    }
}
bool ck(int y, int x) {
    if (y<0 || x<0 || y>N || x>M) { return false; }
    else if (temp[y][x] == 1 || temp[y][x] == 2 || temp[y][x] == 9 || temp[y][x] == 3) { 
        return false; 
    }
    else if (temp[y][x] == 0) { return true; }
}
void bfs() {
    queue<int> dx;
    queue<int> dy;
    int x, y;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (temp[i][j] == 2) {
                dy.push(i);
                dx.push(j);
            }
        }
    }
    while (!dx.empty()) {
        x = dx.front();
        y = dy.front();
        dy.pop();
        dx.pop();
        temp[y][x] = 2;
        //��
        if (ck(y - 1, x) == true) {
            dx.push(x);
            dy.push(y - 1);
        }
        //��
        if (ck(y + 1, x) == true) {
            dx.push(x);
            dy.push(y + 1);
        }
        //��
        if (ck(y, x - 1) == true) {
            dx.push(x - 1);
            dy.push(y);
        }
        //��
        if (ck(y, x + 1) == true) {
            dx.push(x + 1);
            dy.push(y);
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (temp[i][j] == 0) { cnt++; }
        }
    }
    if (cnt >= result) { result = cnt; }
}
void wall(int cnt) {
    if (cnt == 3) { //���� 3�� ����� bfs����
        bfs();
        ary_cp();
    }
    else { // 3���� �� �� ���� ��͸� �����ش�.
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 0) {
                    map[i][j] = 1;
                    wall(cnt + 1);
                    map[i][j] = 0;
                }
            }
        }
    }

}
int main(void) {
    cin >> N >> M;
    //������ �Է� ����
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            temp[i][j] = map[i][j];
        }
    }
    // ���� ����� ���� ��͸� �̿���
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                wall(1);
                map[i][j] = 0;
            }
        }
    }
    cout << result;
}