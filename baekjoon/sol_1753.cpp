// shortest path
#include <iostream>
#include <vector>
#include <queue>

// INF - Emax *  10 �̻����� �����ؾ���
#define INF 3000001 
#define Vmax 20001
#define Emax 300001

using namespace std;

int start, V, E; // ������, ����, ����

// ��带 ���� ����ü
typedef struct NODE {
	int end;
	int val;
};

vector<NODE> Edge[Emax];
int dist[Vmax] = { 0 }; //�ִܰ�θ� ���� �迭

// ���ͽ�Ʈ�� �˰���
void dijkstra() {
	//�켱���� ť ���
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int current = pq.top().second;
		pq.pop();

		// �� ���/ �Ѱ�� ���� ª�� path �����Ͽ� update
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

	// Edge �Է�
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &from, &to, &val);
		Edge[from].push_back(NODE{ to, val });
	}

	// �Ÿ��� ��� ���Ѵ�� �ʱ�ȭ
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}

	dist[start] = 0;

	dijkstra();

	// �������
	for (int i = 1; i <= V; i++) {
		if (dist[i] != INF) 
			printf("%d\n", dist[i]);
		else 
			printf("INF\n");
	}

	return 0;
}