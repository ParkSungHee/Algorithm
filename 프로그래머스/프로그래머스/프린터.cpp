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

        //���� ū ���� ���ؼ� ū���� �ƴϸ� �־����
        if (job.priority != *max_element(priorities.begin(), priorities.end())) {
           printer.push(job);
        }else{
            answer++;
            if(job.idx == location){
                break;
            }
            priorities[job.idx] = 0; //�߿䵵 0���� ����� => ���ϰ����ϴ� �ְ� �ƴϴϱ�
        }
    }

    return answer;
}

int main() {
    vector<int> priorities = {2, 1, 3, 2};
    cout << solution(priorities, 2);

    return 0;
}