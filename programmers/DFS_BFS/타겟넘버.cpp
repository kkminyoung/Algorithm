#include <string>
#include <vector>

using namespace std;

int c = 0; // ���䰹��

void dfs(int size, int idx, int sum, int target, vector<int>& numbers) {
	if (idx == size) {
		if (sum == target) {
			c++;
		}
		return;
	}
	// + ����
	dfs(size, idx + 1, sum + numbers[idx], target, numbers);
	// - ����
	dfs(size, idx + 1, sum - numbers[idx], target, numbers);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	int size = numbers.size();
	dfs(size, 0, 0, target, numbers);
	answer = c;

	return answer;
}
