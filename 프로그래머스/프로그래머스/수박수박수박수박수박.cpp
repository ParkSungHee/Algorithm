#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) { //Ȧ��
            answer += "��";
        }
        else { //¦��
            answer += "��";
        }
    }
    return answer;
}

int main() {
    int n = 3;
    string s = solution(n);
    cout << s;
}