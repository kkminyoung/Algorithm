// ����Ǯ�� ��� 
// 1. BFS�� ���� �ִܰŸ��� min_distance ���Ϳ� ����
// 2. min_distance�� �������� ����(���� ���� ���� ���� �� ������ �Ÿ�)
// 3. ���� �� ������ �������ϱ�

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	vector<int> min_distance(n, 0);
	vector<bool> visited(n, false);
	vector<vector<bool>> graph(n, vector<bool>(n, false));

	// graph �ʱ�ȭ
	for (int i = 0; i < edge.size(); i++) {
		graph[edge[i][0] - 1][edge[i][1] - 1] = 1;
		graph[edge[i][1] - 1][edge[i][0] - 1] = 1;
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		// 1�� ���� ����� ��带 ť�� �ִ´�.
		if (graph[0][i]) {
			q.push(make_pair(i, 1));
			visited[0] = true;
			visited[i] = true;
			min_distance[i] = 1;
		}
	}

	// BFS
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (graph[temp.first][i] && !visited[i]) {
				visited[i] = true;
				min_distance[i] = 1 + temp.second;
				q.push(make_pair(i, min_distance[i]));
			}
		}
	}

	// min_distance �������� ����
	sort(min_distance.begin(), min_distance.end(), greater<int>());

	// ���� �� ������ �Ÿ�
	int max = min_distance.front();

	// ���� �� ����� ������ ����.
	for (int i = 0; i < n; i++) {
		if (min_distance[i] == max)
			answer++;
		else
			break;
	}


	return answer;
}