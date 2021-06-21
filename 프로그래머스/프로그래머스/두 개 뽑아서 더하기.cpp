#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> tmp;
    vector<int> answer;

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            tmp.push_back(numbers[i] + numbers[j]);
        }
    }
    sort(tmp.begin(), tmp.end());
    
    answer.push_back(tmp[0]);
    for (int i = 0; i < tmp.size(); i++) {
        if (answer.back() != tmp[i])
            answer.push_back(tmp[i]);
    }

    return answer;
}

int main() {
    vector<int> numbers = { 2, 1, 3, 4, 1 };
    vector<int> result = solution(numbers);
    for (auto i : result) {
        cout << i << " ";
    }
}