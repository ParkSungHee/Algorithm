#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<>> pq;
    for (auto sc: scoville) {
        pq.push(sc);
    }
    while (pq.top() < K) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        pq.push(first + (second * 2));
        answer++;

        if (pq.size() == 1 && pq.top() < K) {
            return -1;
        }
    }

    return answer;
}

int main() {
    vector<int> scoville = {1, 2, 3, 9, 10, 12};
    int K = 7;
    cout << solution(scoville, K);

    return 0;
}
