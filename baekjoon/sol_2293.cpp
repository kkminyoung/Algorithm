// ���̳��� ���α׷���

#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(void) {

	int n, k;
	int coin[101];
	int d[10001] = { 0, };

	// ��������, �� �Է�
	scanf("%d %d", n, k);

	// �� ���� �ݾ� �Է�
	for (int i = 0; i < n; i++) {
		scanf("%d", coin[i]);
	}

	// ������ȹ��
	d[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= coin[i]) {
				d[j] += d[j - coin[i]];
			}
		}
	}

	// ���� ���
	printf("%d\n", d[k]);

	return 0;
}