#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	vector<int>v;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		v.push_back(i + 1);
	}

	do {
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}