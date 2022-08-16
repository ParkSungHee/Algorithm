#include <iostream>
#include <vector>
using namespace std;

#define MAX 60
int r, c, t;
int house[MAX][MAX];
vector<int> air_cleaner;
vector<pair<int, pair<int, int>>> dust;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    cin >> r >> c >> t;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> house[i][j];
            if (house[i][j] == -1) {
                air_cleaner.emplace_back(i);
            } else if (house[i][j] != 0) {
                dust.push_back({house[i][j], {i, j}});
            }
        }
    }

    while (t--) {
        //1. 확산
        for (auto &i: dust) {
            int spread = 0;
            int d = i.first;
            int x = i.second.first;
            int y = i.second.second;

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c || house[nx][ny] == -1) {
                    continue;
                } else {
                    spread++;
                    house[nx][ny] += (d / 5);
                }
            }
            house[x][y] -= ((d / 5) * spread);
        }

        //2. 바람 순환
        int top_air = air_cleaner[0];

        //2)1-1.왼쪽 아래로
        for (int i = top_air - 1; i > 0; i--) {
            house[i][0] = house[i - 1][0];
        }

        //2)1-2. 위 왼쪽으로
        for (int i = 0; i < c - 1; i++) {
            house[0][i] = house[0][i + 1];
        }

        //2)1-3. 오른쪽 위로
        for (int i = 0; i < top_air; i++) {
            house[i][c - 1] = house[i + 1][c - 1];
        }

        //2)1-4. 아래 오른쪽으로
        for (int i = c - 1; i > 1; i--) {
            house[top_air][i] = house[top_air][i - 1];
        }
        house[top_air][1] = 0; //공기청정기로부터 나오면 청정됨


        int bottom_air = air_cleaner[1];

        //2)2-1.왼쪽 위로
        for (int i = bottom_air + 1; i < r - 1; i++) {
            house[i][0] = house[i + 1][0];
        }

        //2)2-2. 아래 왼쪽으로
        for (int i = 0; i < c - 1; i++) {
            house[r - 1][i] = house[r - 1][i + 1];
        }

        //2)2-3. 오른쪽 아래로
        for (int i = r - 1; i > bottom_air; i--) {
            house[i][c - 1] = house[i - 1][c - 1];
        }

        //2)2-4. 위 오른쪽으로
        for (int i = c - 1; i > 1; i--) {
            house[bottom_air][i] = house[bottom_air][i - 1];
        }
        house[bottom_air][1] = 0;

        //확산으로 인해 숫자 추가된 것 dust에 다시 넣어줘야함 + 공기청정기로 없어진 것 고려
        dust.clear();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (house[i][j] != 0 && house[i][j] != -1) {
                    dust.push_back({house[i][j], {i, j}});
                }
            }
        }
    }
    int result = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result += house[i][j];
        }
    }
    cout << result + 2; //-1을 2번 더해주었기 때문에
    return 0;
}