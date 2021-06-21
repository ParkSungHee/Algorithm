#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

int supo1[5] = { 1, 2, 3, 4, 5 };
int supo2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int supo3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

bool cmp(pair<int, int> left, pair<int, int> right) {
	return left.second > right.second;
}

vector<int> solution(vector<int> answers) {
	vector<pair<int, int>> sum; //수포자num, 맞은 수
	sum.push_back(make_pair(1, 0));
	sum.push_back(make_pair(2, 0));
	sum.push_back(make_pair(3, 0));
	vector<int> result;

	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == supo1[i % 5]) {
			sum[0].second++;
		}
		if (answers[i] == supo2[i % 8]) {
			sum[1].second++;
		}
		if (answers[i] == supo3[i % 10]) {
			sum[2].second++;
		}
	}
	// value 기준 정렬
	sort(sum.begin(), sum.end(), cmp);

	int max = sum[0].second;

	result.push_back(sum[0].first);
	for (int i = 1; i < sum.size(); i++) {
		int max = sum[0].second;
		if (max == sum[i].second) {
			result.push_back(sum[i].first);
		}
	}
	sort(result.begin(), result.end());
	return result;
}

int main() {
	vector<int> answer = { 1,2,3,4,5 };
	vector<int> result = solution(answer);
	for (auto i : result) {
		cout << i << " ";
	}
}