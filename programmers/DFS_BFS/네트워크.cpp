#include <vector>

using namespace std;

bool dfs(vector<vector<int>> & computers, int n) {
	//�̹� ��ȸ�� ����� ����
	if (!computers[n][n])
		return false;
	// ��ȸ������ �˸��� Flag
	computers[n][n] = 0;

	for (int i = 0; i < computers.size(); i++) {
		// ����� ��尡 �ִٸ�
		if (computers[n][i])
			dfs(computers, i);
	}
	return true;
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (computers[i][i] && dfs(computers, i))
			answer++;
	}
	return answer;
}