#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int lefthand = 10, righthand = 12;

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			answer += "L";
			lefthand = numbers[i];
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			answer += "R";
			righthand = numbers[i];
		}
		else {
			int distance_r = 0, distance_l = 0;
			if (numbers[i] == 0) {
				numbers[i] = 11;
			}
			//임시
			int tmp_l = abs(lefthand - numbers[i]);
			int tmp_r = abs(righthand - numbers[i]);

			//키패드 row 내려갈수록 +3되니까... 잘 모르겠다... 되는게 신기 ㅋㅋ
			distance_l = (tmp_l / 3) + (tmp_l % 3);
			distance_r = (tmp_r / 3) + (tmp_r % 3);

			if (distance_l == distance_r) {
				if (hand == "right") {
					answer += "R";
					righthand = numbers[i];
				}
				else if (hand == "left") {
					answer += "L";
					lefthand = numbers[i];
				}
			}
			else {
				if (distance_l > distance_r) {
					answer += "R";
					righthand = numbers[i];
				}
				else {
					answer += "L";
					lefthand = numbers[i];
				}
			}
		}
	}
	return answer;
}

int main() {
	vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
	string hand = "right";
	string answer = solution(numbers, hand);
	cout << answer;
}

