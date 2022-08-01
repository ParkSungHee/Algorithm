#include <iostream>
#include <vector>
using namespace std;

#define MAX 201
char map[MAX][MAX];
char res[MAX][MAX];
int r, c, n;
vector<pair<int, int>> v;

int nx[4] = {0, 0, -1, 1};
int ny[4] = {-1, 1, 0, 0};

void printRes() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << res[i][j];
        }
        cout << "\n";
    }
}

void fourBomb() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == '.') {
                res[i][j] = 'O';
            } else {
                res[i][j] = '.';
                v.emplace_back(i, j);
            }
        }
    }
    for (auto bomb: v) {
        int x = bomb.first;
        int y = bomb.second;

        for (int i = 0; i < 4; i++) {
            int next_x = x + nx[i];
            int next_y = y + ny[i];

            if (next_x < 0 || next_x >= r || next_y < 0 || next_y >= c)
                continue;
            if (res[next_x][next_y] == 'O')
                res[next_x][next_y] = '.';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> n;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }

    if (n % 2 == 0) { //Â¦¼ö
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res[i][j] = 'O';
            }
        }
        printRes();
    } else { //È¦¼ö
        if (n == 1) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    res[i][j] = map[i][j];
                }
            }
            printRes();
        } else if (n % 4 == 3) { //ÅÍÁø°Å
            fourBomb();
            printRes();
        } else if (n % 4 == 1) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    res[i][j] = map[i][j];
                }
            }

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (res[i][j] == 'O') {
                        v.emplace_back(i, j);
                    }
                }
            }
            for (auto bomb: v) {
                int x = bomb.first;
                int y = bomb.second;

                for (int i = 0; i < 4; i++) {
                    int next_x = x + nx[i];
                    int next_y = y + ny[i];

                    if (next_x < 0 || next_x >= r || next_y < 0 || next_y >= c)
                        continue;
                    if (res[next_x][next_y] == '.')
                        res[next_x][next_y] = 'O';
                }
            }

            v.clear();
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (res[i][j] == '.') {
                        v.emplace_back(i, j);
                    }
                }
            }

            for (auto bomb: v) {
                int x = bomb.first;
                int y = bomb.second;

                for (int i = 0; i < 4; i++) {
                    int next_x = x + nx[i];
                    int next_y = y + ny[i];

                    if (next_x < 0 || next_x >= r || next_y < 0 || next_y >= c)
                        continue;
                    if (res[next_x][next_y] == 'O')
                        res[next_x][next_y] = '.';
                }
            }
            printRes();
        }
    }

    return 0;
}