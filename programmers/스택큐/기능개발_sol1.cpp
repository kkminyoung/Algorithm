#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q;

	for (int i = 0; i < progresses.size(); i++) {
		int day = (100 - progresses[i]) % speeds[i];
		if (day == 0) {
			q.push((100 - progresses[i]) / speeds[i]);
		}
		else {
			q.push((100 - progresses[i]) / speeds[i] + 1);
		}
	}

	int current = q.front();
	int count = 1;
	q.pop();
	while (!q.empty()) {
		if (q.front() <= current) {
			q.pop();
			count++;
		}
		else {
			answer.push_back(count);
			count = 1;
			current = q.front();
			q.pop();
		}
	}
	answer.push_back(count);

	return answer;
}