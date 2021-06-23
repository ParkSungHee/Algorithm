#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
	string answer = "";

	for (int i = 0; i < new_id.size(); i++) {
		new_id[i] = tolower(new_id[i]);
	}
	for (int i = 0; i < new_id.size(); i++) {
		if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
			answer.push_back(new_id[i]);
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		if ((answer[i] >= 'a' && answer[i] <= 'z') || (answer[i] >= '0' && answer[i] <= '9') || answer[i] == '-' || answer[i] == '_') {
		}
		else if (answer[i] == '.') {
			if (answer[i + 1] == '.') {
				answer.erase(i + 1, 1);
				i--;
			}
		}
		else {
			answer.erase(i, 1);
			i--;
		}
	
	}
	if (answer[0] == '.') {
		answer.erase(0, 1);
	}
	if (answer.size() > 0) {
		if (answer[answer.size() - 1] == '.') {
			answer.erase(answer.size() - 1, 1);
		}
	}
	if (answer.empty()) {
		answer.push_back('a');
	}
	if (answer.size() >= 16) {
		answer.erase(15);
	}
	if (answer[answer.size()-1] == '.') {
		answer.erase(answer.size() - 1, 1);
	}
	if (answer.size() <= 2) {
		char tmp = answer[answer.size()-1];
		while (answer.size() < 3) {
			answer.push_back(tmp);
		}
	}

	return answer;
}

int main() {
	string s = "...abc...";
	cout << solution(s);
}