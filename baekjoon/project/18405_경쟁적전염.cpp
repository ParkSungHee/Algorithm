#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 201
int n, k, s, x, y;
int arr[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    vector<pair<int, pair<int, int> >> virus;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] != 0)
                virus.push_back({arr[i][j], {i, j}});
        }
    }
    cin >> s >> x >> y;
    sort(virus.begin(), virus.end());

    int cur = 1;
    while (cur <= s) {
        int size = virus.size();
        for (int i = 0; i < size; i++) {
            int curVirus = virus[i].first;
            int curx = virus[i].second.first;
            int cury = virus[i].second.second;

            for (int i = 0; i < 4; i++) {
                int nx = curx + dx[i];
                int ny = cury + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if (arr[nx][ny] > 0)
                    continue;
                arr[nx][ny] = curVirus;
                virus.push_back({curVirus, {nx, ny}});
            }
        }

        if (arr[x - 1][y - 1] > 0)
            break;
        cur++;
    }

    cout << arr[x - 1][y - 1];
    return 0;
}