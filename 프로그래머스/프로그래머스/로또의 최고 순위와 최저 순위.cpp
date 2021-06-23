#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int ranking(int win) {
    int result = 0;
    
    switch (win){
    case 6:
        result = 1;
        break;
    case 5:
        result = 2;
        break;
    case 4:
        result = 3;
        break;
    case 3:
        result = 4;
        break;
    case 2:
        result = 5;
        break;
    default:
        result = 6;
        break;
    }
    return result;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int sum0 = 0;
    int same = 0;
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    for (int i = 0; i < lottos.size(); i++) {
        for (int j = 0; j < win_nums.size(); j++) {
            if (lottos[i] == win_nums[j]) {
                same++;
            }
        } if (lottos[i] == 0) {
            sum0++;
        }
    }
    answer.push_back(ranking(same + sum0));
    answer.push_back(ranking(same)); 
    return answer;
}

int main() {
    vector<int> lottos = { 0, 0, 0, 0, 0, 0 };
    vector<int> win_nums = { 38, 19, 20, 40, 15, 25 };
    vector<int> result = solution(lottos, win_nums);
    cout << result[0] << "," << result[1];
}