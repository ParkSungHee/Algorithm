#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<int> arr1_binary;
	vector<int> arr2_binary;
	vector<string> answer;
	string s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp1 = arr1[i] % 2;
			int tmp2 = arr2[i] % 2;
			arr1_binary.push_back(arr1[i] % 2);
			arr2_binary.push_back(arr2[i] % 2);
			arr1[i] /= 2;
			arr2[i] /= 2;
		}
		reverse(arr1_binary.begin(), arr1_binary.end());
		reverse(arr2_binary.begin(), arr2_binary.end());

		for (int j = 0; j < n; j++) {

			if (arr1_binary[j] == 1 || arr2_binary[j] == 1)
				s += "#";
			else
				s += " ";
		}
		answer.push_back(s);
		s = "";
		arr1_binary.clear();
		arr2_binary.clear();
	}
	return answer;
}

int main() {
	int n = 5;
	vector<int> arr1 = { 9, 20, 28, 18, 11 };
	vector<int> arr2 = { 30, 1, 21, 17, 28 };
	vector<string> result = solution(n, arr1, arr2);


}