#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    if (s.length() % 2 == 0) { //¦��
        answer.push_back(s[s.length() / 2 - 1]);
        answer.push_back(s[s.length() / 2 ]);
    }
    else if (s.length() % 2 == 1) { //Ȧ�� 
        answer.push_back(s[s.length() / 2]);
    }
    return answer;
}
int main() {
    string s = "qwer";
    string result = solution(s);
    cout << result;
}