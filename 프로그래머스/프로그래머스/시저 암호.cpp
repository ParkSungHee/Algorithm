#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            answer.push_back(' ');

        }
        else if (s[i] <= 'z' && s[i] >= 'a') {
            if (s[i] + n > 'z') {
                answer.push_back(s[i] + n - 26);
            }
            else {
                answer.push_back(s[i] + n);
            }
        }
        else if (s[i] <= 'Z' && s[i] >= 'A') {
            if (s[i] + n > 'Z') {
                answer.push_back(s[i] + n - 26);
            }
            else {
                answer.push_back(s[i] + n);
            }
        }
    }

    return answer;
}

int main() {
    string s = "a B z";
    int n = 4;
    cout << solution(s, n);

    return 0;
}