#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int map[60][60];
int n, m;
int minimum = 10000000;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<pair<int, int>> choice;

//0 : 빈칸, 1: 집, 2: 치킨집

int check(pair<int, int> h, vector<pair<int, int>> c) { //house, choice -> choice 중 house와의 거리 제일 가까운 것 return
    int min = 10000000;

    for (auto &i: c) {
        int value = abs(h.first - i.first) + abs(h.second - i.second);

        if (value < min) {
            min = value;
        }
    }

    return min;
}

void backtracking(int idx, int cnt) { // idx : 치킨집 조합을 위함, cnt : 치킨집 카운트
    //cout << "idx: " << idx << ", cnt: " << cnt << endl;
    if (cnt == m) {
        int sum = 0;

        for (auto &i: house) {
            //cout << "check(i, choice) " << check(i, choice) << endl;
            sum += check(i, choice);
        }

        if (sum < minimum) {
            minimum = sum;
        }

        return;
    }

    //전체 치킨집 중에서 m개 골라서(조합) 집과의 치킨거리 다 비교하기 (n과 m)
    for (int i = idx; i < chicken.size(); i++) { // i = idx !
        //cout << "(1) i: " << i << ", cnt: " << cnt << endl;
        choice.emplace_back(chicken[i].first, chicken[i].second);
        backtracking(i + 1, cnt + 1);
        choice.pop_back();
        //cout << "size: " << choice.size() << endl;
        //cout << "(2) i: " << i << ", cnt: " << cnt << endl;
    }
}

int main() { //n과 m으로 돌리며 cnt가 m이랑 같을 때가 여러번 있는데, 그때마다 min값 갱신
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];

            if (map[i][j] == 1) {
                house.emplace_back(i, j);
            } else if (map[i][j] == 2) {
                chicken.emplace_back(i, j);
            }
        }
    }
    backtracking(0, 0);

    cout << minimum;

    return 0;
}
