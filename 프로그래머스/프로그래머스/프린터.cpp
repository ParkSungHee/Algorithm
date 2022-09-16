#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Printer {
    int priority;
    int idx;
};

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<Printer> printer;
    for (int i = 0; i < priorities.size(); i++) {
        printer.push({priorities[i], i});
    }

    while (!printer.empty()) {
        Printer job = printer.front();
        printer.pop();

        //제일 큰 값과 비교해서 큰값이 아니면 넣어야함
        if (job.priority != *max_element(priorities.begin(), priorities.end())) {
           printer.push(job);
        }else{
            answer++;
            if(job.idx == location){
                break;
            }
            priorities[job.idx] = 0; //중요도 0으로 만들기 => 구하고자하는 애가 아니니까
        }
    }

    return answer;
}

int main() {
    vector<int> priorities = {2, 1, 3, 2};
    cout << solution(priorities, 2);

    return 0;
}