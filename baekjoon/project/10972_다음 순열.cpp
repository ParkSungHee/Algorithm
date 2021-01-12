#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int>permutation_vs;

int main() {
	cin >> n;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		permutation_vs.push_back(tmp);
	}
	
	if (next_permutation(permutation_vs.begin(), permutation_vs.end())) {
		for (int i = 0; i < n; i++) {
			cout << permutation_vs[i] <<" ";
		}
	}
	else
		cout << "-1";

	return 0;
}