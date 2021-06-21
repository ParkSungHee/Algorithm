#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	vector<int> flag(participant.size());

	for (int i = 0; i < completion.size(); i++){ //3
		for (int j = 0; j < participant.size(); j++) { //4
			if (participant[j] == completion[i] && flag[j]!=1) {
				flag[j] = 1;
				break;
			}
		}
	}

	for (int i = 0; i < participant.size(); i++) {
		if (flag[i] == 0) {
			answer = participant[i];
		}
	}

	return answer;
}

int main() {
	vector<string> participant = { "marina", "josipa", "nikola", "vinko", "filipa", "filipa"  };
	vector<string> completion = { "josipa", "filipa", "marina", "nikola", "filipa" };

	string result = solution(participant, completion);
	cout << result;
}