#include <iostream>
using namespace std;

#define MAX 30
int map[MAX][MAX];
int f, result = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void backtracking(int x, int y, int visit) {
    if (x == 4 && y == 4) {
        if (f == visit) {
            result++;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && map[nx][ny] != 1) {
            map[nx][ny] = 1;
            backtracking(nx, ny, visit + 1);
            map[nx][ny] = 0;
        }
    }
}

//��� ���� ������ �ع����� �������� ���� �ִ� ����� ��, ����ġ�� ������ �Ű� �Ƚᵵ ��
int main() {
    int k, x, y;
    cin >> k;
    f = 25 - k; //�� ���� ĭ ��

    while (k--) {
        cin >> x >> y;
        map[x - 1][y - 1] = 1; //��
    }
    map[0][0] = 1;

    backtracking(0, 0, 1);
    cout << result;

    return 0;
}
