#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int cnt;
int map[25][25];
bool visit[25][25] = { 0, };
int pos[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };	//�� �� �� ��

void dfs(int a, int b) {
	visit[a][b] = true;
	cnt++;				//���� ������ count

	for (int i = 0; i < 4; i++) {		//�����¿� Ž��
		int row = a + pos[i][0];		//��
		int column = b + pos[i][1];		//��
		
		if (row >= 0 && row < n && column >= 0 && column < n) { //1. �迭�� ������ �����ϴ���
			if (map[row][column] == 1) {		//2. ������ ���� ���ִ���
				if (!visit[row][column])	//3. �湮�� ���� ���� ���̿�����
					dfs(row, column);
			}
		}
	}
}

int main() {
	string line;
	vector<int>result;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < n; j++) {
			map[i][j] = line[j]-'0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && !visit[i][j]) {
				cnt = 0;
				dfs(i, j);
				result.push_back(cnt);

			}
		}
	}
	
	cout << result.size() << endl;
	sort(result.begin(), result.end());
	for (int i : result)
		cout << i << endl;
	

	return 0;
}