#include <string>
#include <vector>

using namespace std;

int c = 0; // 정답갯수

void dfs(int size, int idx, int sum, int target, vector<int>& numbers) {
	if (idx == size) {
		if (sum == target) {
			c++;
		}
		return;
	}
	// + 연산
	dfs(size, idx + 1, sum + numbers[idx], target, numbers);
	// - 연산
	dfs(size, idx + 1, sum - numbers[idx], target, numbers);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	int size = numbers.size();
	dfs(size, 0, 0, target, numbers);
	answer = c;

	return answer;
}
