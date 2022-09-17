#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());

    for (int i = 0; i < citations.size(); i++) {
        int h_index = citations.size() - i; //�̻� �ο�� ���� ����
        if(citations[i] >= h_index)
            return h_index;
    }
    return answer;
}

int main() {
    vector<int> citations = {3, 0, 6, 1, 5};
    cout << solution(citations);

    return 0;
}