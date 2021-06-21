#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(pair<int, double>& a, pair<int, double>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

// 실패율 = 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수
vector<int> solution(int N, vector<int> stages) { //실패율이 높은 스테이지부터 내림차순
	vector<int> answer;
	vector<pair<int, double>> pair_answer;

	int fault = stages.size();
	for (int i = 0; i < N; i++) {
		int player = 0;
		for (int j = 0; j < stages.size(); j++) {
			if (i + 1 == stages[j]) {
				player++;
			}
		}
		if (player == 0) {
			pair_answer.push_back(make_pair(i + 1, 0));
		}
		else {
			pair_answer.push_back(make_pair(i + 1, (double)player / fault));
		}
		fault -= player;
	}

	sort(pair_answer.begin(), pair_answer.end(), comp);

	for (auto i : pair_answer) {
		answer.push_back(i.first);
	}

	return answer;
}

int main() {
	int n = 5; //전체 스테이지
	vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 }; //사용자가 멈춰있는 스테이지 번호(+ 명)
	vector<int> result = solution(n, stages);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}