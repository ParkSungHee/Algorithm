#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int flag = 0;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
            for (int z = j+1; z < nums.size(); z++) {
                int tmp = nums[i] + nums[j] + nums[z];
                for (int k = 3; k < tmp; k++) {
                    if ((tmp % k == 0)) {
                        flag = 1;
                    }
                }
                if (flag == 0) {
                    answer++;
                }
                flag = 0;
            }
        }
    }
    return answer;
}

int main() {
    vector<int> nums = { 1,2,7,6,4 };
    cout << solution(nums);
}