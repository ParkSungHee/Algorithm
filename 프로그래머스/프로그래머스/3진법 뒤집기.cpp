#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> v;

	for (int i = n; i > 0; i /= 3) {
		int tmp = i % 3;
		v.push_back(i % 3);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		answer += (v[i] * pow(3, v.size() - 1 - i));
	}
	return answer;
}

int main() {
	int n = 125;
	cout << solution(n);
}