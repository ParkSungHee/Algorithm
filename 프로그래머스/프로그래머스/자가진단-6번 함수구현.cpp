#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int>answer;
	vector<int>flag(arr.size());
	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		int sum = 0;
		for (int j = i + 1; j < arr.size(); j++) {
			if (flag[j] == 0) {
				if (arr[i] == arr[j]) {
					sum++;
					flag[i] = 1;
					flag[j] = 1;
				}
			}
		}
		if (sum != 0) {
			answer.push_back(sum+1);
		}
	}
	if (answer.size() == 0) {
		answer.push_back(-1);
	}
	return answer;
}

int main() {
	vector<int> v = { 1,2,3,3,3,3,4,4 };
	vector<int> v2 = { 3,2,4,4,2,5,2,5,5 };
	vector<int> v3 = { 3,5,7,9,1 };

	vector<int> result = solution(v3);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}