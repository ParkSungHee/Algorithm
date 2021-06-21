#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

long long solution(long long n) {
	long long answer = 0;
	string s = to_string(n);
	sort(s.begin(), s.end(), greater<char>());
	return stoll(s);
}

int main() {
	long long n = 118372;
	cout << solution(n);
}