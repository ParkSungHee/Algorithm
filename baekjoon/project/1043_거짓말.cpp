#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 51
int n, m, t, num, people, cnt = 0;
queue<int> trueKnow;
vector<int> party[MAX];
bool res[MAX]; //과장된 이야기를 할 수 있는 파티 여부
bool tKnow[MAX]; //진실 아는지 여부

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> t;
    while (t--) {
        cin >> num;
        trueKnow.push(num);
        tKnow[num] = true;
    }

    for (int i = 1; i <= m; i++) {
        cin >> people;
        while (people--) {
            cin >> num;
            party[i].push_back(num);
        }
    }

    //bfs
    while (!trueKnow.empty()) {
        int cur = trueKnow.front();
        trueKnow.pop();

        for (int i = 1; i <= m; i++) {
            if (find(party[i].begin(), party[i].end(), cur) != party[i].end()) { //찾았으면
                res[i] = true;

                for (int &j: party[i]) {
                    if (!tKnow[j]) {
                        tKnow[j] = true;
                        trueKnow.push(j);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        if (!res[i]) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
