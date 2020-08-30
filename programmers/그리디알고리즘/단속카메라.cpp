#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1; // ī�޶� ���
	// ����
	sort(routes.begin(), routes.end());
	// ó�� ���� ������ �κ�
	int curr = routes[0][1];

	for (auto a : routes) {
		// ��ġ�� �κ� �� ����ٸ� ī�޶� ��ġ
		if (curr < a[0]) {
			answer++; // ī�޶� ��� ����
			curr = a[1]; // ������ �κ� ������Ʈ
		}
		// ��ġ�� �κ� ����ٸ�
		if (curr >= a[1])
			curr = a[1]; // ī�޶� ��ġ���� �ʰ� ������ �κ� ������Ʈ��
	}
	return answer;
}