#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	deque<int> pq; //덱사용
	string op;
	int n;

	for (int i = 0; i < operations.size(); i++) {
		op = operations.at(i);
		n = stoi(op.substr(2));

		// 큐에 주어진 숫자 삽입
		if (op[0] == 'I') {
			pq.push_back(n);
			sort(pq.begin(), pq.end());
		}
		else {
			if (pq.empty())
				continue;
			if (n == 1) //큐에서 최댓값 삭제
				pq.pop_back();
			else if(n== -1) //큐에서 최솟값 삭제
				pq.pop_front();
		}
	}

	//비어있으면 [0,0]
	if (pq.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	//비어있지 않으면 [최댓값, 최솟값]
	else {
		answer.push_back(pq.back());
		answer.push_back(pq.front());
	}

	return answer;

}