#include <iostream>
#include <cstring>
#include <queue>

#define MAX 1001

using namespace std;

int connected[MAX][MAX];
int visited[MAX];
queue<int> q;
int n, m;

int answer = 0;

// dfs(깊이 우선 탐색)
void dfs(int v) {
	visited[v] = 1; // 방문했음을 표시
	for (int i = 1; i <= n; i++) {
		// 연결되어있고 방문을 안했으면
		if (connected[v][i] && !visited[i]) {
			dfs(i);
			answer += 1;
		}
	}
}


int main(void) {

	// 예제 입력
	// *** N : 정점의 개수
	// *** M : 간선의 개수
	// *** V : 탐색을 시작할 정점의 번호
	cin >> n;
	cin >> m;
	int v=1;

	// 메모리 할당
	memset(connected, 0, sizeof(connected));
	memset(visited, 0, sizeof(visited));

	// 간선 연결
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		connected[a][b] = 1;
		connected[b][a] = 1;
	}

	// dfs
	dfs(v);
	cout << answer;

	return 0;
}