#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	vector<int> temp1{ 1, 2, 3, 4, 5};
	vector<int> temp2{ 2, 1, 2, 3, 2, 4, 2, 5};
	vector<int> temp3{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

	vector<int> count{ 0,0,0 };

	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == temp1[i % 5]) count[0]++;
		if (answers[i] == temp2[i % 8]) count[1]++;
		if (answers[i] == temp3[i % 10]) count[2]++;
	}

	int maxCount = max(count[0], max(count[1], count[2]));

	for (int i = 0; i < 3; i++) {
		if (count[i] == maxCount) 
			answer.push_back(i + 1);
	}

	return answer;
}