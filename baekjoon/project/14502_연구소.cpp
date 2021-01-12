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
        //상
        if (ck(y - 1, x) == true) {
            dx.push(x);
            dy.push(y - 1);
        }
        //하
        if (ck(y + 1, x) == true) {
            dx.push(x);
            dy.push(y + 1);
        }
        //좌
        if (ck(y, x - 1) == true) {
            dx.push(x - 1);
            dy.push(y);
        }
        //우
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
    if (cnt == 3) { //벽을 3개 세울시 bfs실행
        bfs();
        ary_cp();
    }
    else { // 3개가 될 때 까지 재귀를 돌려준다.
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
    //테이터 입력 받음
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            temp[i][j] = map[i][j];
        }
    }
    // 벽을 세우기 위해 재귀를 이용함
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