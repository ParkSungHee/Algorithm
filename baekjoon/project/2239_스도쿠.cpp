#include <iostream>
#include <vector>
using namespace std;

#define MAX 101
int board[MAX][MAX];
bool width[MAX][MAX], vertical[MAX][MAX], square[MAX][MAX]; //a번째 가로, 세로, 사각형에 존재하는 b라는 숫자는 이미 존재한다

vector<int> availNumber(int i, int j) { //가로, 세로, 사각형 안에 없는 숫자를 v에 넣어줌
    vector<int> v;

    for (int k = 1; k <= 9; k++) {
        if (!width[i][k] && !vertical[j][k] && !square[(i / 3) * 3 + (j / 3)][k]) {
            //cout << "k: " << k << endl;
            v.push_back(k);
        }
    }
    return v;
}

void sol(int i, int j) {
    if (i > 8) { //종료 조건
        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                cout << board[x][y];
            }
            cout << "\n";
        }
        exit(0);
    }

    if (board[i][j] != 0) { //1) 0 아니면
        if (j == 8) {
            sol(i + 1, 0);
        } else {
            sol(i, j + 1);
        }
    } else { //2) 0 이면
        vector<int> avail = availNumber(i, j);
        for (int u: avail) { //작은 숫자 넣으면서 v가 0이면 백트래킹으로 돌아가, 그 다음 숫자를 넣음
            //cout << "i: " << i << ", j: " << j << ", u: " << u << endl;
            width[i][u] = true;
            vertical[j][u] = true;
            square[(i / 3) * 3 + (j / 3)][u] = true;
            board[i][j] = u;
            if (j == 8) {
                sol(i + 1, 0);
            } else {
                sol(i, j + 1);
            }
            width[i][u] = false;
            vertical[j][u] = false;
            square[(i / 3) * 3 + (j / 3)][u] = false;
            board[i][j] = 0;
        }
    }
}

int main() {
    string st;
    for (int i = 0; i < 9; i++) {
        cin >> st;
        for (int j = 0; j < 9; j++) {
            int num = st[j] - '0';

            board[i][j] = num;
            if (num != 0) {
                width[i][num] = true;
                vertical[j][num] = true;
                square[(i / 3) * 3 + (j / 3)][num] = true;
            }
        }
    }

    sol(0, 0);
    return 0;
}