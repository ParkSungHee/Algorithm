#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int b, c, d, p, result1 = 0;
double result2;
vector<int> burger_price;
vector<int> side_price;
vector<int> drink_price;

int Find() {
    sort(burger_price.begin(), burger_price.end(), greater<>());
    sort(side_price.begin(), side_price.end(), greater<>());
    sort(drink_price.begin(), drink_price.end(), greater<>());

    unsigned int burger = burger_price.size();
    unsigned int side = side_price.size();
    unsigned int drink = drink_price.size();
    unsigned int minRes = min({burger, side, drink});

    for (int i = 0; i < minRes; i++) {
        result2 += burger_price[i] * 0.9;
        result2 += side_price[i] * 0.9;
        result2 += drink_price[i] * 0.9;
    }

    for (unsigned int i = minRes; i < burger_price.size(); i++) {
        result2 += burger_price[i];
    }
    for (unsigned int i = minRes; i < side_price.size(); i++) {
        result2 += side_price[i];
    }
    for (unsigned int i = minRes; i < drink_price.size(); i++) {
        result2 += drink_price[i];
    }

    return result2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> b >> c >> d;

    for (int i = 0; i < b; i++) {
        cin >> p;
        result1 += p;
        burger_price.push_back(p);
    }

    for (int i = 0; i < c; i++) {
        cin >> p;
        result1 += p;
        side_price.push_back(p);
    }
    for (int i = 0; i < d; i++) {
        cin >> p;
        result1 += p;
        drink_price.push_back(p);
    }

    cout << result1 << "\n" << Find();

    return 0;
}