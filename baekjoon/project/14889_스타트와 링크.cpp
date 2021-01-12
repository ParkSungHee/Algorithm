#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

int n, result;
int map[20][20];
int team1[10], team2[10];
int pick[20];

void update() {
	int team1_size = 0, team2_size = 0;
	for (int i = 0; i < n; ++i) {
		/* �� �����ϱ� */
		if (pick[i] == 0) //������ �ʾҴٸ�
			team1[team1_size++] = i;
		else {
			team2[team2_size++] = i;
		}
	}

	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n / 2; ++i) {
		for (int j = i + 1; j < n / 2; ++j) {
			sum1 += (map[team1[i]][team1[j]] + map[team1[j]][team1[i]]); //map[team1�� ��� ���][team1�� ��� ���]
			sum2 += (map[team2[i]][team2[j]] + map[team2[j]][team2[i]]);
		}
	}
	if (result > abs(sum1 - sum2)) {
		result = abs(sum1 - sum2);
	}
}

void dfs(int cur, int pick_count) { //pick_count = ��� �̾Ҵ���
	if (pick_count == (n / 2)) {
		update();//���� ���
		return;
	}
	for (int i = cur; i < n; ++i) {
		pick[i] = 1;
		dfs(i + 1, pick_count + 1);
		pick[i] = 0; //���� �ʾҴٷ� �ٲ�
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	result = 0x7fffffff; //��� int�� ���� ū ��(21��)
	dfs(0, 0);
	cout << result;

	return 0;
}
