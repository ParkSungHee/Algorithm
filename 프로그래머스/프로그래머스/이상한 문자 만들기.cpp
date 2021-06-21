#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	int count = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			answer.push_back(' ');
			count = 0;
		} else if (count % 2 == 0) { //Â¦¼ö
			answer.push_back(toupper(s[i]));
			count++;
		} else { //È¦¼ö
			answer.push_back(tolower(s[i]));
			count++;
		}

	}
	return answer;
}

int main() {
	string s = "Hello eVeryone";
	cout << solution(s);
}