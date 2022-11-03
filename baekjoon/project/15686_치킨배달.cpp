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

//0 : ��ĭ, 1: ��, 2: ġŲ��

int check(pair<int, int> h, vector<pair<int, int>> c) { //house, choice -> choice �� house���� �Ÿ� ���� ����� �� return
    int min = 10000000;

    for (auto &i: c) {
        int value = abs(h.first - i.first) + abs(h.second - i.second);

        if (value < min) {
            min = value;
        }
    }

    return min;
}

void backtracking(int idx, int cnt) { // idx : ġŲ�� ������ ����, cnt : ġŲ�� ī��Ʈ
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

    //��ü ġŲ�� �߿��� m�� ���(����) ������ ġŲ�Ÿ� �� ���ϱ� (n�� m)
    for (int i = idx; i < chicken.size(); i++) { // i = idx !
        //cout << "(1) i: " << i << ", cnt: " << cnt << endl;
        choice.emplace_back(chicken[i].first, chicken[i].second);
        backtracking(i + 1, cnt + 1);
        choice.pop_back();
        //cout << "size: " << choice.size() << endl;
        //cout << "(2) i: " << i << ", cnt: " << cnt << endl;
    }
}

int main() { //n�� m���� ������ cnt�� m�̶� ���� ���� ������ �ִµ�, �׶����� min�� ����
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
