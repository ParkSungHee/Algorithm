#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 100001
int n, m, k, x, y, num, node;
vector<int> edge[MAX];
int in_degree[MAX]; //����
int woo[MAX]; //����

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

        if (num == 1) { //����
            if (in_degree[node] == 0) {
                woo[node]++;
                if (woo[node] == 1) { //ó�� ���� ������ ��
                    for (auto next: edge[node]) {
                        in_degree[next]--;
                    }
                }
            } else {
                isTrue = false;
            }
        } else { //�ı�
            if (woo[node] > 0) {
                woo[node]--;
                if (woo[node] == 0) { //��� ��
                    for (auto next: edge[node]) {
                        in_degree[next]++;
                    }
                }
            } else { // ġƮŰ �Ἥ ���� �ǹ��� �ı��Ϸ���
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