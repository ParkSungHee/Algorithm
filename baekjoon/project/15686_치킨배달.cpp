#include <iostream>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

int map[60][60];
int N, M;
int minimum = 10000000;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<pair<int, int>> choice;

int check(pair<int, int> house, vector<pair<int, int>> choice){
    int min = 10000000;

    for (int i = 0; i < choice.size(); i++){
        int value = abs(house.first - choice[i].first) + abs(house.second - choice[i].second);

        if (value < min){
            min = value;
        }
    }

    return min;
}

void backtracking(int idx, int cnt){
    if (cnt == M){
        int sum = 0;

        for (int i = 0; i < house.size(); i++){
            sum += check(house[i], choice);
        }

        if (sum < minimum){
            minimum = sum;
        }

        return;
    }

    for (int i = idx; i < chicken.size(); i++){
        choice.push_back({ chicken[i].first, chicken[i].second });
        backtracking(i + 1, cnt + 1);
        choice.pop_back();
    }
}

int main(void){
    cin >> N >> M;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];

            if (map[i][j] == 1){
                house.push_back({ i, j });
            }
            else if (map[i][j] == 2){
                chicken.push_back({ i, j });
            }
        }
    }
    backtracking(0, 0);

    cout << minimum;

    return 0;
}
