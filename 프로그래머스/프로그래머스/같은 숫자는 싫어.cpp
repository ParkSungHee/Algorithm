#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr){
    vector<int> answer;

    answer.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++) {
        if (answer.back() != arr[i]) {
            answer.push_back(arr[i]);
        }
    }
    return answer;
}

int main() {
    vector<int> arr = { 1,1,3,3,0,1,1 };
    vector<int> result = solution(arr);
    for (auto i : result) {
        cout << i << " ";
    }
}