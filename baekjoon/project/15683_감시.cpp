#include<iostream>
#include<vector>
using namespace std;

int n, m;
int map[10][10], temp[10][10];
int result = 1000000000;
vector<pair<int, int>>v;
//시계방향
const int dy[] = { -1, 0, 1, 0 }; //상, 하
const int dx[] = { 0, 1, 0, -1 }; //오, 왼

vector<pair<int, int>> rotation(int here, int dir) {
    vector<pair<int, int>> change;
    int y = v[here].first;
    int x = v[here].second;

    if (map[y][x] == 1) { //한쪽 방향
        int _y = y;
        int _x = x;
        while (true) {
            int ny = _y + dy[dir];
            int nx = _x + dx[dir];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] != 6) {
                if (map[ny][nx] == 0) {
                    map[ny][nx] = '#';
                    change.push_back({ ny, nx }); 
                }
                _y = ny;
                _x = nx;
            }
            else 
                break;
        }
    }
    else if (map[y][x] == 2) {
        for (int i = 0; i <= 2; i += 2) {// 상,하 / 오,왼
            int _y = y;
            int _x = x;

            while (true) {
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];

                if (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] != 6) {
                    if (map[ny][nx] == 0) {
                        map[ny][nx] = '#';
                        change.push_back({ ny, nx }); 
                    }
                    _y = ny;
                    _x = nx;
                }
                else 
                    break;
            }
        }
    }
    else if (map[y][x] == 3) {
        for (int i = 0; i < 2; i++) {
            int _y = y;
            int _x = x;
            while (true) {
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] != 6) {
                    if (map[ny][nx] == 0) {
                        map[ny][nx] = '#';
                        change.push_back({ ny, nx }); 
                    }
                    _y = ny;
                    _x = nx;
                }
                else 
                    break;
            }
        }
    }
    else if (map[y][x] == 4) {
        for (int i = 0; i < 3; i++) {
            int _y = y;
            int _x = x;
            while (true) {
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] != 6) {
                    if (map[ny][nx] == 0) {
                        map[ny][nx] = '#';
                        change.push_back({ ny, nx }); 
                    }
                    _y = ny;
                    _x = nx;
                }
                else 
                    break;
            }
        }
    }
    else if (map[y][x] == 5) {
        for (int i = 0; i < 4; i++) {
            int _y = y;
            int _x = x;
            while (true) {
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];

                if (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] != 6) {
                    if (map[ny][nx] == 0) {
                        map[ny][nx] = '#';
                        change.push_back({ ny, nx }); 
                    }
                    _y = ny;
                    _x = nx;
                }
                else 
                    break;
            }
        }
    }
    return change;
}

void dfs(int here) { //하나하나를 0~v.size로 번호를 매긴 것
    if (here == v.size()) {
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0)
                    cnt++;
            }
        }
        result = min(cnt, result);

        return;
    }

    for (int k = 0; k < 4; k++) {
        vector<pair<int, int>> _change = rotation(here, k);
        dfs(here + 1);
        for ( auto b : _change ) {
            map[b.first][b.second] = 0; //다시 rotaion하기 위함
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] >= 1 && map[i][j] <= 5)
                v.push_back({ i, j });
        }
    }
    dfs(0);
    cout << result << "\n";

    return 0;
}