#include <iostream>
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
	double answer = 0;

	for (int i = 0; i < arr.size(); i++) {
		answer += arr[i];
	}
	answer /= arr.size();
	return answer;
}

int main() {
	vector<int> arr = { 1,2,3,4 };
	double result = solution(arr);
	cout << result;
}