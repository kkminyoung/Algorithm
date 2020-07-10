#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

int connected[MAX][MAX];
int visited[MAX];
queue<int> q;
int n, m, v;

// 1. dfs(깊이 우선 탐색)
void dfs(int v) {
	cout << v << " ";
	visited[v] = 1; // 방문했음을 표시
	for (int i = 1; i <= n; i++) {
		// 연결되어있고 방문을 안했으면
		if (connected[v][i] && !visited[i]) {
			dfs(i);
		}
	}
}

// 2. bfs(너비 우선 탐색)
void bfs(int v) {
	visited[v] = 1;
	q.push(v);

	while (!q.empty()) {
		v = q.front();
		q.pop();

		cout << v << " "; 
		for (int i = 1; i <= n; i++) {
			if (connected[v][i] && !visited[i]) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}

int main(void) {

	// 예제 입력
	// *** N : 정점의 개수
	// *** M : 간선의 개수
	// *** V : 탐색을 시작할 정점의 번호
	cin >> n >> m >> v;

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

	// 1. dfs
	dfs(v);
	cout << "\n";

	memset(visited, 0, sizeof(visited));

	// 2. bfs
	bfs(v);
	cout << "\n";

	return 0;
}