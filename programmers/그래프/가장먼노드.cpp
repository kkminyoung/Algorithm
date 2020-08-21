// 문제풀이 방법 
// 1. BFS를 통해 최단거리를 min_distance 벡터에 저장
// 2. min_distance를 내림차순 정렬(가장 앞의 값이 가장 먼 노드와의 거리)
// 3. 가장 먼 노드들의 갯수구하기

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

	// graph 초기화
	for (int i = 0; i < edge.size(); i++) {
		graph[edge[i][0] - 1][edge[i][1] - 1] = 1;
		graph[edge[i][1] - 1][edge[i][0] - 1] = 1;
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		// 1번 노드와 연결된 노드를 큐에 넣는다.
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

	// min_distance 내림차순 정렬
	sort(min_distance.begin(), min_distance.end(), greater<int>());

	// 가장 먼 노드와의 거리
	int max = min_distance.front();

	// 가장 먼 노드의 갯수를 센다.
	for (int i = 0; i < n; i++) {
		if (min_distance[i] == max)
			answer++;
		else
			break;
	}


	return answer;
}