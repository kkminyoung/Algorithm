#include <vector>

using namespace std;

bool dfs(vector<vector<int>> & computers, int n) {
	//이미 순회한 노드라면 멈춤
	if (!computers[n][n])
		return false;
	// 순회했음을 알리는 Flag
	computers[n][n] = 0;

	for (int i = 0; i < computers.size(); i++) {
		// 연결된 노드가 있다면
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