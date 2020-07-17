// 다이나믹 프로그래밍

#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(void) {

	int n, k;
	int coin[101];
	int d[10001] = { 0, };

	// 동전개수, 합 입력
	scanf("%d %d", n, k);

	// 각 동전 금액 입력
	for (int i = 0; i < n; i++) {
		scanf("%d", coin[i]);
	}

	// 동적계획법
	d[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= coin[i]) {
				d[j] += d[j - coin[i]];
			}
		}
	}

	// 정답 출력
	printf("%d\n", d[k]);

	return 0;
}