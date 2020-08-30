// 크루스칼 알고리즘을 이용해 MST 찾는 문제

#include <string>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;
int d[MAX];

// 최상위 부모 찾기
int find(int node) {
	// 부모가 자기자신이면 현재 노드가 최상위 부모
	if (node == d[node])
		return node;
	// 아니라면 위로 올라가며 부모의 부모를 찾음
	else
		return d[node] = find(d[node]);
}

// 간선의 가중치를 기준으로 오름차순 정렬
int cmp(const vector<int> &a, const vector<int> &b) {
	return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	// 1. 부모를 담음. 처음에는 자기 자신이 부모
	for (int i = 0; i < n; i++) {
		d[i] = i;
	}
	// 2. 간선의 가중치 기준 정렬
	sort(costs.begin(), costs.end(), cmp);

	// 3. 모든 간선을 검사
	for (int i = 0; i < costs.size(); i++) {
		int start = find(costs[i][0]);
		int end = find(costs[i][1]);
		int cost = costs[i][2];

		// 4. start와 end가 아직 연결되지 않았다면
		if (start != end) {
			d[start] = end; // start의 부모를 end로 설정
			answer += cost; // 간선의 가중치를 결과에 더해줌
		}
	}
	return answer;
}