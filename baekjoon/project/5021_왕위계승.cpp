#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
using namespace std;

int n, m;
double maxBlood = -1;
string builder, child, parent1, parent2, result;
map<string, vector<string>> family; // parent, 자식
map<string, pair<int, double>> in_degree; //자신, parent, 피
vector<string> wants;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> builder;
    in_degree[builder] = {0, 1};

    for (int i = 0; i < n; i++) {
        cin >> child >> parent1 >> parent2;

        //기존에 이미 parent 있다면 추가 x, 없다면 추가
        if (in_degree.find(parent1) == in_degree.end()) {
            in_degree[parent1] = {0, 0};
        }
        if (in_degree.find(parent2) == in_degree.end()) {
            in_degree[parent2] = {0, 0};
        }
        in_degree[child] = {2, 0}; //부모, 일단 피 0

        family[parent1].push_back(child);
        family[parent2].push_back(child);
    }

    for (int i = 0; i < m; i++) {
        cin >> child;
        wants.push_back(child);
    }

    queue<string> q;
    for (const auto &name: in_degree) {
        if (name.second.first == 0) { //parent 0이면 (=in_degree 0)
            q.push(name.first);
        }
    }

    while (!q.empty()) {
        string parent = q.front();
        q.pop();

        for (const string &kid: family[parent]) { //자식들 보기
            in_degree[kid].second += in_degree[parent].second; //부모꺼 더하기
            --in_degree[kid].first;
            if (in_degree[kid].first == 0) {
                q.push(kid);
                in_degree[kid].second /= 2; //자식은 1/2
            }
        }
    }

    for (const string& want: wants) { //원하는 사람 중 제일 큰 second(피) 찾기
        if (maxBlood < in_degree[want].second) {
            maxBlood = in_degree[want].second;
            result = want;
        }
    }
    cout << result;

    return 0;
}