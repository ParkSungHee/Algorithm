#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k, m, v, c;
vector<pair<int, int>> jewel;
vector<int> bag;
long long result = 0;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

//가방을 돌면서 보석의 우선순위에 따라 가격을 더해줌
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        jewel.emplace_back(m, v);
    }
    for (int i = 0; i < k; i++) {
        cin >> c;
        bag.push_back(c);
    }
    sort(jewel.begin(), jewel.end(), cmp);
    sort(bag.begin(), bag.end());

    int idx = 0;
    priority_queue<int> pq;

    for (int i = 0; i < k; i++) {
        int bag_size = bag[i];

        for (int j = idx; j < n; j++) {
            if (jewel[j].first <= bag_size) {
                pq.push(jewel[idx].second);
                idx++;
            } else {
                break;
            }
        }
        if (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
    }
    cout << result;

    return 0;
}
