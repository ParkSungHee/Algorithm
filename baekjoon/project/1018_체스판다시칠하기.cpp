/*
* 1주차 - BFS
지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M*N 크기의 보드를 찾았다. 어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 지민이는 이 보드를 잘라서 8*8 크기의 체스판으로 만들려고 한다.
체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다. 따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.
보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8*8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다. 당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.
-------
입력
첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. B는 검은색이며, W는 흰색이다.
-------
출력
첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char arr[50][50];	//입력 받는 체스판
int arrnum[50][50];	//1,0으로 바꿈
int arrW[8][8];	//W로 시작하는 체스판
int arrB[8][8];	//B로 시작하는 체스판
int result;

void confirm(int a, int b) {
	int tmp1 = 0, tmp2 = 0; //1:B , 2:W
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arrnum[a + i][b + j] != arrB[i][j]) tmp1++;
			if (arrnum[a + i][b + j] != arrW[i][j]) tmp2++;
		}
	}
	result = min(result, tmp1);
	result = min(result, tmp2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, m;
	result = 64;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'B')
				arrnum[i][j] = 1;
			else
				arrnum[i][j] = 0;
		}
	}

	//arrW, arrB 초기화
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			arrB[i][j] = (i + j + 1) % 2;
			arrW[i][j] = (i + j) % 2;
		}
	}
	
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) { //i,j가 시작점
			confirm(i, j);
		}
	}
	
	cout << result << "\n";

	return 0;
}