#include <iostream>
#include <vector>
using namespace std;

#define MAX 11
int arr[MAX][MAX];
int tmp[MAX][MAX];
int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int result = 0;

void virus(int x, int y) { //dfs
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx > n || ny < 0 || ny > m)
            continue;
        if (tmp[nx][ny] == 0) {
            tmp[nx][ny] = 2;
            virus(nx, ny);
        }
    }
}

int getScore() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmp[i][j] == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}

void dfs(int cnt) { //dfs로 벽 설치
    if (cnt == 3) {
        //바이러스 퍼뜨리기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp[i][j] = arr[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tmp[i][j] == 2)
                    virus(i, j);
            }
        }

        //안전영역 최대인 것으로 교체
        result = max(result, getScore());
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                cnt++;
                dfs(cnt);
                arr[i][j] = 0;
                cnt--;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    dfs(0);
    cout << result;
    return 0;
}