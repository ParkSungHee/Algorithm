#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> days, answer;
    for (int i = 0; i < progresses.size(); i++) {
        int ele = ceil((100 - progresses[i]) / (double)speeds[i]);
        days.push_back(ele);
    }

    int fr = days[0];
    int cnt = 1;

    for (int i = 1; i < days.size(); i++) {
        if (fr >= days[i]) {
            cnt++;
        } else {
            answer.push_back(cnt);
            fr = days[i];
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    return answer;
}

//배포 때마다 몇개의 기능이 배포되는지 return


int main() {
    vector<int> progresses = {95, 90, 99, 99, 80, 99};
    vector<int> speeds = {1, 1, 1, 1, 1, 1};

    vector<int> res = solution(progresses, speeds);
    for (auto &i: res) {
        cout << i << " ";
    }
    return 0;
}