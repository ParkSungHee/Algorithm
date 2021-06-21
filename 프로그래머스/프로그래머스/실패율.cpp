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

// ������ = ���������� ���������� ���� Ŭ�������� ���� �÷��̾��� �� / ���������� ������ �÷��̾� ��
vector<int> solution(int N, vector<int> stages) { //�������� ���� ������������ ��������
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
	int n = 5; //��ü ��������
	vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 }; //����ڰ� �����ִ� �������� ��ȣ(+ ��)
	vector<int> result = solution(n, stages);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}