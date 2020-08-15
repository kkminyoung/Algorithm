#include <string>
#include <vector>

using namespace std;

int visited[201] = { 0, }; // 방문여부를 알리는 Flag

void DFS(int i, int n, vector<vector<int>> &computers) {
	for (int j = 0; j < n; j++)
		// 연결되어있고 방문하지 않았다면
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