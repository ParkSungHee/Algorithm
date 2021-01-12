#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	vector<int>v;
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	if (prev_permutation(v.begin(), v.end())) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
	}
	else
		cout << "-1";
	


	return 0;
}