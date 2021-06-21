#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> tmp;
    vector<int>::iterator iter;
    int min;

    tmp = arr;
    sort(tmp.begin(), tmp.end());
    min = tmp[0];
    
    if (arr.size() == 1) {
        answer.push_back(-1);
    } else {
        for (iter = arr.begin(); iter != arr.end(); iter++) {
            if (min == *iter) {
                arr.erase(iter);
                answer = arr;
                break;
           }
        }
    }

    return answer;
}

int main() {
    vector<int> arr = { 10 };
    vector<int> answer = solution(arr);
    for (auto i : answer) {
        cout << i << " ";
    }
}