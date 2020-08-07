#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 아래에서 위로 올라오면서 숫자들을 더한 best 값을 찾는 방식으로!!!
int solution(vector<vector<int>> triangle) {
	int answer = 0;
	vector<vector<int>> best(triangle.size(), vector<int>(triangle.size()));

	// 제일 아래줄 숫자들 넣어주기
	for (int i = 0; i < triangle.size(); i++) {
		int end = triangle.size() - 1;
		best[end][i] = triangle[end][i];
	}

	// best[i][j] = triangle[i][j] + max(best[i + 1][j], best[i + 1][j + 1]);
	for (int i = triangle.size() - 2; i >= 0; i--) {
		for (int j = 0; j < triangle[i].size(); j++) {
			best[i][j] = triangle[i][j] + max(best[i + 1][j], best[i + 1][j + 1]);
		}
	}

	// 최대값은 제일 위에 오는 값
	answer = best[0][0];

	return answer;
}