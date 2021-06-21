#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int>flag(n);
	bool isErase;

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	for (auto i = lost.begin(); i != lost.end();) {
		isErase = false;

		for (auto j = reserve.begin(); j != reserve.end(); j++) {
			if (*i == *j) {
				lost.erase(i);
				reserve.erase(j);
				isErase = true;
				break;
			}
		}
		if (isErase == false) {
			++i;
		}
	}

	for (int i = 0; i < lost.size(); i++) {
		flag[lost[i] - 1] = 1; // 잃어버린 사람
	}
	for (int j = 0; j < reserve.size(); j++) {
		flag[reserve[j] - 1] = 2; //여벌의 체육복 가져온 사람
	}

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (flag[i] == 1) {
				if (flag[i + 1] == 2) {
					flag[i] = 0;
					flag[i + 1] = 0;
					continue;
				}
			}
		}
		else if (i == n - 1) {
			if (flag[i] == 1) {
				if (flag[i - 1] == 2) {
					flag[i] = 0;
					flag[i - 1] = 0;
					break;
				}
			}
		}
		else {
			if (flag[i] == 1) {
				if (flag[i - 1] == 2) {
					flag[i] = 0;
					flag[i - 1] = 0;
					continue;
				}
				else if (flag[i + 1] == 2) {
					flag[i] = 0;
					flag[i + 1] = 0;

				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (flag[i] == 0 || flag[i] == 2) {
			answer++;
		}
	}
	return answer;
}
int main() {
	int n = 7;
	vector<int> lost = { 2, 4 ,5, 6 };
	vector<int> reserve = { 1, 3 ,6 };
	int result = solution(n, lost, reserve);
	cout << result;
}