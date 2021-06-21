/*
문자열 길이 4 or 6 + 숫자로만 구성 = True
나머지 false
*/
#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

bool solution(string s) {
    bool answer = false;
    regex confirm("[0-9]+");
    if (s.size() == 4 || s.size() == 6) {
        if (regex_match(s, confirm)) {
            answer = true;
        }
    }
    return answer;
}

int main() {
    string s = "a234";
    bool result = solution(s);
    cout << result;
}