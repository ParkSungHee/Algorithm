#include <iostream>
#include <string>

using namespace std;

int solution(string s) {
    int answer = 0;
    answer = stoi(s);
    return answer;
}

int main() {
    string s = "+1234";
    cout << solution(s); 
}