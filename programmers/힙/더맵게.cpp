#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int size = scoville.size();

	// min heap 사용
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < size; i++) {
		pq.push(scoville[i]);
	}

	while (pq.top() < K && pq.size() > 1) {
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();

		pq.push(first + second * 2);
		answer++;
	}

	// 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 -1을 return
	if (pq.top() < K)
		return -1;

	return answer;
}