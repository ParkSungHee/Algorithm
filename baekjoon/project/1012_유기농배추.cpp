#include<iostream>
#include<queue>
using namespace std;

int n, m, k;
int map[50][50] = { 0, };
int visit[50][50] = { 0, };
int cnt=0;
int pos[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

void dfs(int a, int b) {
	for (int i = 0; i < 4; i++) {
		int x = a + pos[i][0];
		int y = b + pos[i][1];

		if (y >= 0 && y < n && x >= 0 && x < m) {
			if (map[x][y] == 1 && !visit[x][y]) {
				visit[x][y] = 1;
				dfs(x, y);
			}
		}
	}
}

int main() {
	int tmpn, tmpm;
	int testcase;
	vector<int>result;

	cin >> testcase;

	while (testcase--) {
		cnt = 0;
		cin >> n >> m >> k;

		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				map[i][j] = 0;
				visit[i][j] = 0;
			}
		}

		while (k--) {
			cin >> tmpn >> tmpm;
			map[tmpm][tmpn] = 1;
		}
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1 && !visit[i][j]) {
					cnt++;
					visit[i][j] = 1;
					dfs(i, j);

				}
			}
		}
		cout << cnt<< endl;
	}
	return 0;
}