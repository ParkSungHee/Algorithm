#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, result = 0;
vector<vector<int>> keys;
vector<int> quest;

//조합 만들고 vector 돌면서 최댓값 구하자
void backtracking(int num, int s) {
    cout << "num: " << num << ", s:  "<<s << "\n";
    if (s == n) {
        int cnt = 0;

        for (auto &key: keys) {
            bool isFlag = true;
            for (auto &kk: key) {
                auto it = find(quest.begin(), quest.end(), kk);
                if (it == quest.end()) {
                    isFlag = false;
                    break;
                }
            }
            if (isFlag) {
                cnt++;
            }
        }
        result = max(result, cnt);
        return;
    }

    for (int i = num; i <= 2 * n; i++) {
        cout << "i: " << i << "\n";
        quest.push_back(i);
        backtracking(i + 1, s + 1); //i+1 ???
        quest.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    keys.resize(m, vector<int>(k));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> keys[i][j];
        }
    }

    backtracking(1, 0);
    cout << result;
    return 0;
}
