#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	stack<int> s; // ���ÿ��� �ε����� �־� �ð��� ���

	for (int i = 0; i < prices.size(); i++) {
		// ������ ������ ���
		while (!s.empty() && prices[s.top()] > prices[i]) {
			answer[s.top()] = i - s.top(); // �������� ������ �ð� ����ؼ� ���信
			s.pop();
		}
		s.push(i);
	}

	// ���ÿ� �����ִ� �͵� ����ó������(���������� �������� ���� �͵�)
	while (!s.empty()) {
		answer[s.top()] = prices.size() - s.top() - 1; // �ѽð� - ���۽ð� - 1
		s.pop();
	}

	return answer;
}