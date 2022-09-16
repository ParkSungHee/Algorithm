#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) { //������ ���ο�, ������ ���ο� �־ �ִ� ���ϸ� ��
    int answer;
    vector<int> max_v, min_v;

    for (auto &i: sizes) {
        if (i[0] < i[1]) { //������ min ū�� max ������
            min_v.push_back(i[0]);
            max_v.push_back(i[1]);
        } else {
            min_v.push_back(i[1]);
            max_v.push_back(i[0]);
        }
    }

    sort(min_v.begin(), min_v.end(), greater<>());
    sort(max_v.begin(), max_v.end(), greater<>());

    answer = min_v[0] * max_v[0];
    return answer;
}

int main() {
    vector<vector<int>> sizes = {{60, 50},
                                 {30, 70},
                                 {60, 30},
                                 {80, 40}};
    cout << solution(sizes);

    return 0;
}