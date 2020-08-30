// ũ�罺Į �˰����� �̿��� MST ã�� ����

#include <string>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;
int d[MAX];

// �ֻ��� �θ� ã��
int find(int node) {
	// �θ� �ڱ��ڽ��̸� ���� ��尡 �ֻ��� �θ�
	if (node == d[node])
		return node;
	// �ƴ϶�� ���� �ö󰡸� �θ��� �θ� ã��
	else
		return d[node] = find(d[node]);
}

// ������ ����ġ�� �������� �������� ����
int cmp(const vector<int> &a, const vector<int> &b) {
	return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	// 1. �θ� ����. ó������ �ڱ� �ڽ��� �θ�
	for (int i = 0; i < n; i++) {
		d[i] = i;
	}
	// 2. ������ ����ġ ���� ����
	sort(costs.begin(), costs.end(), cmp);

	// 3. ��� ������ �˻�
	for (int i = 0; i < costs.size(); i++) {
		int start = find(costs[i][0]);
		int end = find(costs[i][1]);
		int cost = costs[i][2];

		// 4. start�� end�� ���� ������� �ʾҴٸ�
		if (start != end) {
			d[start] = end; // start�� �θ� end�� ����
			answer += cost; // ������ ����ġ�� ����� ������
		}
	}
	return answer;
}