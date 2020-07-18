#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

vector<pair<int, int>> timeTable; // ȸ�ǽð�(����,��) ���� ����

int N; // ȸ���� ��

int main(void) {
	int start; //ȸ���� ���۽ð�
	int end; //ȸ���� ������ �ð�
	int check[1000001];

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &start, &end);
		timeTable.push_back({ end,start });
	}

	sort(timeTable.begin(), timeTable.end()); // ȸ�ǽð� ����


	// greedy approach
	int max_result = 0; // �ִ� ����� �� �ִ� ȸ���� ����
	int time = 0;
	for (int i = 0; i < N; i++) {
		if (timeTable[i].second >= time) {
			max_result++;
			time = timeTable[i].first;
		}
	}

	// ����� ���
	printf("%d", max_result);

	return 0;
}