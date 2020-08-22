// �� - ��ũ��Ʈ�ѷ� ����
// ������ ���ڸ��� �ü�� �������� ��� 
// SJF(Shortest Job First) ����� ���ö�
// �����ϰ� Ǯ �� �־���!


#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct compare {
	bool operator()(vector<int> a, vector<int> b) {
		return a.at(1) > b.at(1);
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int i = 0;
	int t = 0; 

	sort(jobs.begin(), jobs.end());

	priority_queue<vector<int>, vector<vector<int>>, compare> ready_queue;
	
	while (!ready_queue.empty() || i < jobs.size()) {
		if (jobs.size() > i && t >= jobs[i][0]) {
			ready_queue.push(jobs[i++]);
			continue;
		}

		if (!ready_queue.empty()) {
			t += ready_queue.top()[1];
			answer += t - ready_queue.top()[0];
			ready_queue.pop();
		}
		else
			t = jobs[i][0];		
	}

	answer = answer / jobs.size();

	return answer;
}