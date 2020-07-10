#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

int connected[MAX][MAX];
int visited[MAX];
queue<int> q;
int n, m, v;

// 1. dfs(���� �켱 Ž��)
void dfs(int v) {
	cout << v << " ";
	visited[v] = 1; // �湮������ ǥ��
	for (int i = 1; i <= n; i++) {
		// ����Ǿ��ְ� �湮�� ��������
		if (connected[v][i] && !visited[i]) {
			dfs(i);
		}
	}
}

// 2. bfs(�ʺ� �켱 Ž��)
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

	// ���� �Է�
	// *** N : ������ ����
	// *** M : ������ ����
	// *** V : Ž���� ������ ������ ��ȣ
	cin >> n >> m >> v;

	// �޸� �Ҵ�
	memset(connected, 0, sizeof(connected));
	memset(visited, 0, sizeof(visited));

	// ���� ����
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