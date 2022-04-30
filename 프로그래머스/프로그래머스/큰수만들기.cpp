#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;

    }
    return a.second > b.second;
}

string solution(string number, int k) {
    string answer;
    vector<pair<int, char>> v;

    for (int i = 0; i < number.size(); i++) {
        v.push_back(make_pair(i, number[i]));
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < number.size() - k; i++) {
        answer += v[i].second;
    }

    return answer;
}

int main() {
    cout << solution("1231234", 3);
}

//string solution(string number, int k) {
//    string answer = "";
//    int idx = -1;
//    for (int i = 0; i < number.size() - k; i++) {
//        char maxV = ' ';
//        for (int j = idx + 1; j <= k + i; j++) {
//            if (maxV < number[j]) {
//                maxV = number[j];
//                idx = j;
//            }
//        }
//        answer += maxV;
//    }
//    return answer;
//}