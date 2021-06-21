#include <iostream>
using namespace std;

int solution(int n) {
	int answer = 0;

	do {
		answer += (n % 10);
		n /= 10;
	} while (n > 0);

	return answer;
}

int main() {
	int n = 1234;
	int result = solution(n);
	cout << result;
}