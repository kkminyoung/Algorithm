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

// dfs(���� �켱 Ž��)
void dfs(int v) {
	visited[v] = 1; // �湮������ ǥ��
	for (int i = 1; i <= n; i++) {
		// ����Ǿ��ְ� �湮�� ��������
		if (connected[v][i] && !visited[i]) {
			dfs(i);
			answer += 1;
		}
	}
}


int main(void) {

	// ���� �Է�
	// *** N : ������ ����
	// *** M : ������ ����
	// *** V : Ž���� ������ ������ ��ȣ
	cin >> n;
	cin >> m;
	int v=1;

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

	// dfs
	dfs(v);
	cout << answer;

	return 0;
}