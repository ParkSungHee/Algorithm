#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> arr(n+1);

	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i * i < n+1; i++) {
		for (int j = i * i; j < n+1; j += i) {
			arr[j] = 1; //소수가 아닌 수
		}
	}

	for (int i = 2; i < n+1; i++) {
		if (arr[i] == 0) {
			answer++;
		}
	}

	return answer;
}

int main() {
	int n = 10;
	cout << solution(n);
}