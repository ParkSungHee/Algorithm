#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<char> alpha = {'A', 'E', 'I', 'O', 'U'};
vector<string> dict;

void backtracking(int cnt, string word) {
    if (cnt == word.size()) {
        dict.push_back(word);
        return;
    }
    for (int i = 0; i < 5; i++) {
        backtracking(cnt, word + alpha[i]);
    }
}

int solution(string word) {
    int answer = 0;
    for (int i = 1; i <= 5; i++) {
        backtracking(i, "");
    }
    sort(dict.begin(), dict.end());
    answer = find(dict.begin(), dict.end(), word) - dict.begin() + 1;
    return answer;
}

int main() {
    string word = "EIO";
    cout << solution(word);

    return 0;
}