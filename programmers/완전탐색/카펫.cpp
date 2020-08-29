#include <vector>
#include <string>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	int total = brown + yellow;
	for (int height = 3; ; height++) {
		// total�� height�� ������ �������� ��츸!
		if (!(total % height)) {
			int weight = total / height;
			// �׵θ� �����Ѱ� ����������� ������!!
			if (((height - 2)*(weight - 2)) == yellow) {
				answer.push_back(weight);
				answer.push_back(height);
				break;
			}
		}
	}


	return answer;
}