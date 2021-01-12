#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

int map[4][8];
int check[5] = { 0, };

void clockwise(int a) {
	int tmp = map[a][7];
	for (int i = 6; i >= 0; i--) {
		map[a][i + 1] = map[a][i];
	}
	map[a][0] = tmp;
}
void counterclockwise(int a) {
	int tmp = map[a][0];
	for (int i = 0; i < 7; i++) {
		map[a][i] = map[a][i+1];
	}
	map[a][7] = tmp;
}

int main() {
	char c;
	int k;
	int num, dir;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> c;

			map[i][j] = c - '0';
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> num >> dir;

		if (num == 1) { //직접 안닿아있는 뒤에건 check가 0인지 확인해야함(초기값)
			check[1] = dir;
			if (map[0][2] != map[1][6])
				check[2] = check[1] * -1;
			if (check[2] != 0 && map[1][2] != map[2][6])
				check[3] = check[2] * -1;
			if (check[3] != 0 && map[2][2] != map[3][6])
				check[4] = check[3] * -1;
		}
		else if (num == 2) {
			check[2] = dir;
			if (map[0][2] != map[1][6])
				check[1] = check[2] * -1;
			if (map[1][2] != map[2][6])
				check[3] = check[2] * -1;
			if (check[3] != 0 && map[2][2] != map[3][6])
				check[4] = check[3] * -1;
		}
		else if (num == 3) {
			check[3] = dir;
			if (map[2][2] != map[3][6])
				check[4] = check[3] * -1;
			if (map[1][2] != map[2][6])
				check[2] = check[3] * -1;
			if (check[2] != 0 && map[0][2] != map[1][6])
				check[1] = check[2] * -1;

		}
		else if (num == 4) {
			check[4] = dir;
			if (map[2][2] != map[3][6])
				check[3] = check[4] * -1;
			if (check[3] != 0 && map[1][2] != map[2][6])
				check[2] = check[3] * -1;
			if (check[2] != 0 && map[0][2] != map[1][6])
				check[1] = check[2] * -1;
		}
		
		if (check[1] == 1) clockwise(0);
		else if (check[1] == -1) counterclockwise(0);

		if (check[2] == 1) clockwise(1);
		else if (check[2] == -1) counterclockwise(1);

		if (check[3] == 1) clockwise(2);
		else if (check[3] == -1) counterclockwise(2);

		if (check[4] == 1) clockwise(3);
		else if (check[4] == -1) counterclockwise(3);

		memset(check, 0, sizeof(check));
	}
	
	int ans = map[0][0] + (map[1][0] * 2) + (map[2][0] * 4) + (map[3][0] * 8); 
	cout << ans;
}