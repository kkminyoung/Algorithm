#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	deque<int> pq; //�����
	string op;
	int n;

	for (int i = 0; i < operations.size(); i++) {
		op = operations.at(i);
		n = stoi(op.substr(2));

		// ť�� �־��� ���� ����
		if (op[0] == 'I') {
			pq.push_back(n);
			sort(pq.begin(), pq.end());
		}
		else {
			if (pq.empty())
				continue;
			if (n == 1) //ť���� �ִ� ����
				pq.pop_back();
			else if(n== -1) //ť���� �ּڰ� ����
				pq.pop_front();
		}
	}

	//��������� [0,0]
	if (pq.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	//������� ������ [�ִ�, �ּڰ�]
	else {
		answer.push_back(pq.back());
		answer.push_back(pq.front());
	}

	return answer;

}