#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;
	vector<char> ch;
	sort(strings.begin(), strings.end());
	for (auto i : strings) {
		ch.push_back(i[n]);
	}
	sort(ch.begin(), ch.end());
	ch.erase(unique(ch.begin(), ch.end()), ch.end());

	for (int i = 0; i < ch.size(); i++) {
		for (int j = 0; j < strings.size(); j++) {
			if (ch[i] == (strings[j])[n]) {
				answer.push_back(strings[j]);
			}
		}
	}
	return answer;
}

int main() {
	vector<string> strings = { "abce", "abcd", "cdx" };
	int n = 2;
	vector<string> result = solution(strings, n);
	for (auto i : result) {
		cout << i << " ";
	}
}