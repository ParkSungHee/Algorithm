#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

#define MAX 101

int N, M, C;
int cnt = 0;
int arr[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void DFS(int x, int y) {
	visit[x][y] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (arr[nx][ny] == 0 && !visit[nx][ny]) {
			DFS(nx, ny);
		}
	}
}

int main() {
	vector <int> vec;
	cin >> N >> M >> C;

	while (C--) {
		int x1, x2, y1, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				arr[i][j] = 1;
				visit[i][j] = true;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0 && !visit[i][j]) {
				cnt = 0;
				DFS(i, j);
				vec.push_back(cnt);
			}
		}
	}
	sort(vec.begin(), vec.end());
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";

	return 0;
}