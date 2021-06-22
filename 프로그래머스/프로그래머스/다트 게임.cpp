#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int index = -1 ;
	vector <int> numbers;

	for (int i = 0; i < dartResult.size(); i++) {
		if (dartResult[i] == 'S') {} 
		else if (dartResult[i] == 'D') {
			numbers[index] = numbers[index] * numbers[index];
		}
		else if (dartResult[i] == 'T') {
			numbers[index] = numbers[index] * numbers[index] * numbers[index];
		}
		else if (dartResult[i] == '*') {
			numbers[index] = numbers[index] * 2;
			int tmp = numbers[index];
			if (index > 0) {
				numbers[index-1] = numbers[index-1] * 2;
				int tmp2 = numbers[index - 1];
			}
		}
		else if (dartResult[i] == '#') {
			numbers[index] = numbers[index] * (-1);
		}
		else{
			if (dartResult[i+1] == '0') {
				numbers.push_back(10);
				i++;
			}
			else {
				int tmp = dartResult[i] - '0';
				numbers.push_back(dartResult[i]-'0');
			}
			index++;
		}
	}
	for (int i = 0; i < numbers.size(); i++) {
		answer += numbers[i];
	}
	return answer;
}

int main() {
	string dartResult = "1T2D3D#";
	int result = solution(dartResult);
	cout << result;
}