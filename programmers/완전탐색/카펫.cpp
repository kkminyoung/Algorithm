#include <vector>
#include <string>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	int total = brown + yellow;
	for (int height = 3; ; height++) {
		// total이 height로 나누어 떨어지는 경우만!
		if (!(total % height)) {
			int weight = total / height;
			// 테두리 제외한게 노란색개수와 같으면!!
			if (((height - 2)*(weight - 2)) == yellow) {
				answer.push_back(weight);
				answer.push_back(height);
				break;
			}
		}
	}


	return answer;
}