#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 100001
int n, m, k, x, y, num, node;
vector<int> edge[MAX];
int in_degree[MAX]; //기존
int woo[MAX]; //영우

int main() {
    cin >> n >> m >> k;

    while (m--) {
        cin >> x >> y;
        edge[x].push_back(y);
        in_degree[y]++;
    }

    bool isTrue = true;
    while (k--) {
        cin >> num >> node;

        if (num == 1) { //생성
            if (in_degree[node] == 0) {
                woo[node]++;
                if (woo[node] == 1) { //처음 만든 정점일 때
                    for (auto next: edge[node]) {
                        in_degree[next]--;
                    }
                }
            } else {
                isTrue = false;
            }
        } else { //파괴
            if (woo[node] > 0) {
                woo[node]--;
                if (woo[node] == 0) { //어렵 ㅠ
                    for (auto next: edge[node]) {
                        in_degree[next]++;
                    }
                }
            } else { // 치트키 써서 세운 건물을 파괴하려함
                isTrue = false;
            }
        }
    }
    if (isTrue) {
        cout << "King-God-Emperor";
    } else {
        cout << "Lier!";
    }

    return 0;
}