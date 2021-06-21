#include <iostream>
#include <string>
using namespace std;

bool solution(string s){
    bool answer = true;
    int p_sum = 0;
    int y_sum = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'p' || s[i] == 'P') {
            p_sum += 1;
        }
        else if (s[i] == 'y' || s[i] == 'Y') {
            y_sum += 1;
        }
    }
    if (p_sum != y_sum) {
        answer = false;
    }

    return answer;
}

int main() {
    string s = "Pyy";
    cout << solution(s);
}