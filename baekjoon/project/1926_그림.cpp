#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[501][501];
int visit[501][501];
int pos[4][2] = { {-1,0},
				  {1,0},
				  {0,-1},
				  {0,1} };	//╩С го аб ©Л

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int cnt = 0;
	int size = 0;
	int maxsize = -21470000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 || visit[i][j] == 1) 
				continue;
			cnt++;
			queue<pair<int, int>> q;
			q.push({ i,j });
			visit[i][j] = 1;
			size = 1;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					int xx = cur.first + pos[k][0];
					int yy = cur.second + pos[k][1];
					if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
					if (map[xx][yy] == 0 || visit[xx][yy] == 1) continue;
					q.push({ xx,yy });
					visit[xx][yy] = 1;
					size++;
				}
			}
			//cout << size << endl;
			maxsize = max(maxsize, size);
		}
	}
	cout << cnt <<endl;
	if (cnt == 0) {
		cout << "0";
	}
	else {
		cout << maxsize;
	}
}