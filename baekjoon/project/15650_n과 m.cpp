#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int>v;
	int n, m;

	cin >> n;
	for (int i = 0; i < n; i++) {
		v.push_back(i + 1);
	}
	cin >> m;

	do {
		
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}