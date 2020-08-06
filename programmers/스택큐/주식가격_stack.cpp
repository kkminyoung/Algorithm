#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	stack<int> s; // 스택에는 인덱스를 넣어 시간을 계산

	for (int i = 0; i < prices.size(); i++) {
		// 가격이 떨어진 경우
		while (!s.empty() && prices[s.top()] > prices[i]) {
			answer[s.top()] = i - s.top(); // 떨어지기 까지의 시간 계산해서 정답에
			s.pop();
		}
		s.push(i);
	}

	// 스택에 남아있는 것들 정답처리과정(최종적으로 떨어지지 않은 것들)
	while (!s.empty()) {
		answer[s.top()] = prices.size() - s.top() - 1; // 총시간 - 시작시간 - 1
		s.pop();
	}

	return answer;
}