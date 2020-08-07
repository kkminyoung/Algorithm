#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// �Ʒ����� ���� �ö���鼭 ���ڵ��� ���� best ���� ã�� �������!!!
int solution(vector<vector<int>> triangle) {
	int answer = 0;
	vector<vector<int>> best(triangle.size(), vector<int>(triangle.size()));

	// ���� �Ʒ��� ���ڵ� �־��ֱ�
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

	// �ִ밪�� ���� ���� ���� ��
	answer = best[0][0];

	return answer;
}