#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    if (a + b > b + a)
        return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer;
    vector<string> v;

    for (auto number: numbers) {
        v.push_back(to_string(number));
    }

    sort(v.begin(), v.end(), compare);

    for (const auto &i: v) {
        answer += i;
    }

    if(v.at(0) == "0"){ //0, 0, 0인 경우 -> 0으로 처리
        answer = "0";
    }
    return answer;
}

int main() {
    vector<int> numbers = {0, 0, 0};
    cout << solution(numbers);
}