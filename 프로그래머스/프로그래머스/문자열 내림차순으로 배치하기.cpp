#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool comp(char s1, char s2) {
    return s1 > s2;
}

string solution(string s) {
    sort(s.begin(), s.end(), comp);
    return s;
}

int main() {
    string s = "Zbcdefg";
    cout << solution(s);
}