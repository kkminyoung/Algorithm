// shortest path
#include <iostream>
#include <vector>
#include <queue>

// INF - Emax *  10 이상으로 설정해야함
#define INF 3000001 
#define Vmax 20001
#define Emax 300001

using namespace std;

int start, V, E; // 시작점, 정점, 간선

// 노드를 담을 구조체
typedef struct NODE {
	int end;
	int val;
};

vector<NODE> Edge[Emax];
int dist[Vmax] = { 0 }; //최단경로를 담을 배열

// 다익스트라 알고리즘
void dijkstra() {
	//우선순위 큐 사용
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int current = pq.top().second;
		pq.pop();

		// 두 경로/ 한경로 둘중 짧은 path 선택하여 update
		for (int k = 0; k < Edge[current].size(); k++) {
			int new_val = dist[current] + Edge[current][k].val;
			int before_val = dist[Edge[current][k].end]; 
			if (new_val < before_val) {
				dist[Edge[current][k].end] = new_val;
				pq.push({ -1 * new_val, Edge[current][k].end });
			}
		}
	}
}

int main() {
	cin >> V >> E >> start;

	int from, to, val;

	// Edge 입력
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &from, &to, &val);
		Edge[from].push_back(NODE{ to, val });
	}

	// 거리는 모두 무한대로 초기화
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}

	dist[start] = 0;

	dijkstra();

	// 정답출력
	for (int i = 1; i <= V; i++) {
		if (dist[i] != INF) 
			printf("%d\n", dist[i]);
		else 
			printf("INF\n");
	}

	return 0;
}