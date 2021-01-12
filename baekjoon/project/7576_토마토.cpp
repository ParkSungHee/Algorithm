#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int map[1002][1002];
int visit[1002][1002];
int pos[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }; //좌 우 상 하

int main() {
	int n, m;
	queue<pair<int, int>>q;

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1)	//1인 지점에서 동시에 bfs를 돌게 하기 위해
				q.push({ i,j });
			if (map[i][j] == 0)
				visit[i][j] = -1; //map == 0인곳 visit 초기화
		}
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int x = cur.first + pos[i][0];
			int y = cur.second + pos[i][1];

			if (x >= 0 && x < n && y >= 0 && y < m)
				if (visit[x][y] < 0) {
					visit[x][y] = visit[cur.first][cur.second] + 1;
					q.push({ x,y });
				}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == -1) {
				cout << -1;
				return 0;
			}
			ans = max(ans, visit[i][j]);
		}
	}
	cout << ans;

	return 0;
}