#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int tmp;
	int min = 1000000000, max = -1000000000;
	vector<int>num;
	vector<int>symbol;


	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		num.push_back(tmp);
	}
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		for (int j = 0; j < tmp; j++)
			symbol.push_back(i);
	}

	do {
		int value = num[0];
		for (int i = 0; i < symbol.size(); i++) {
			switch (symbol[i]){
			case 0: value += num[i + 1]; break;
			case 1: value -= num[i + 1]; break;
			case 2: value *= num[i + 1]; break;
			case 3: value /= num[i + 1]; break;
			}
		}
		if (min > value)
			min = value;
		if (max < value)
			max = value;
	} while (next_permutation(symbol.begin(), symbol.end()));

	cout << max << "\n"<<min;
}