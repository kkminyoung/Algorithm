// 힙 - 디스크컨트롤러 문제
// 문제를 보자마자 운영체제 수업에서 배운 
// SJF(Shortest Job First) 방식이 떠올라서
// 수월하게 풀 수 있었다!


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