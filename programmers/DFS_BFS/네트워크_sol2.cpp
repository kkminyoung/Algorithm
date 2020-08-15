#include <string>
#include <vector>

using namespace std;

int visited[201] = { 0, }; // �湮���θ� �˸��� Flag

void DFS(int i, int n, vector<vector<int>> &computers) {
	for (int j = 0; j < n; j++)
		// ����Ǿ��ְ� �湮���� �ʾҴٸ�
		if (i != j && computers[i][j] && !visited[j]) {
			visited[j] = 1;
			DFS(j, n, computers);
		}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++)
		if (!visited[i]) {
			visited[i] = 1;
			DFS(i, n, computers);
			answer++;
		}

	return answer;
}