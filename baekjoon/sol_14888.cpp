// 14888�� - ��Ʈ��ŷ
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[12];
int op[5]; // ������

const int MAX = 1000000001;

int n;

int maxResult = -MAX;
int minResult = MAX;

void DFS(int plus, int minus, int mul, int divide, int cnt, int sum) {
	// cnt �� n�� �� �� ����� ����
	if (cnt == n) {
		maxResult = max(maxResult, sum);
		minResult = min(minResult, sum);
	}

	// �� �����ڰ� �������� �� ����
	if (plus > 0) {
		DFS(plus - 1, minus, mul, divide, cnt + 1, sum + arr[cnt]);
	}
	if (minus > 0) {
		DFS(plus, minus - 1, mul, divide, cnt + 1, sum - arr[cnt]);
	}
	if (mul > 0) {
		DFS(plus, minus, mul - 1, divide, cnt + 1, sum * arr[cnt]);
	}
	if (divide > 0) {
		DFS(plus, minus, mul, divide - 1, cnt + 1, sum / arr[cnt]);
	}

}




int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &op[i]);
	}
	DFS(op[0], op[1], op[2], op[3], 1, arr[0]);

	printf("%d\n", maxResult);
	printf("%d", minResult);

	return 0;
}