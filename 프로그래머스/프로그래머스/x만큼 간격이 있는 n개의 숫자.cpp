#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
	vector<long long> answer;

	for (int i = 1; i <= n; i++) {
		answer.push_back(i * x); 
	}
	return answer;
}

int main() {
	int x = -4;
	int n = 2;
	vector<long long> result = solution(x, n);
	for (auto i : result) {
		cout << i << " ";
	}
}