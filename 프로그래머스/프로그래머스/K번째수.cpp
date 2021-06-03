#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int i = 0; i < commands.size(); i++) {
		vector<int> tmp;

		for (int j = commands[i][0]; j <= commands[i][1]; j++) {
			tmp.push_back(array[j - 1]);
		}

		sort(tmp.begin(), tmp.end());
		answer.push_back(tmp[commands[i][2] - 1]);
	}

	return answer;
}

int main() {
	vector<int> answer = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands({
		vector<int>({ 2,5,3}),
		vector<int>({ 4,4,1}),
		vector<int>({ 1,7,3})
		});

	vector<int> result = solution(answer, commands);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
}