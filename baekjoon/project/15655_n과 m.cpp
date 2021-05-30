#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	int tmp;
	vector<int> v;
	vector<int> compare; // 0과 1을 저장 할 벡터 생성

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		compare.push_back(0);
	}

	for (int i = 0; i < v.size() - m; i++) {
		compare.push_back(1);
	}

	sort(v.begin(), v.end());
	sort(compare.begin(), compare.end());

	do {
		for (int i = 0; i < compare.size(); i++) {
			if (compare[i] == 0) {
				cout << v[i] << " ";
			}
		}
		cout << endl;
	} while (next_permutation(compare.begin(), compare.end()));

	return 0;
}