#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int connected[26][26];
int sizeCheck[400];
int check[4][2] = { {-1,0},{1,0},{0,-1}, {0,1} };

int cnt;
int n;

bool isInside(int a, int b) {
	return (a >= 0 && a < n) && (b >= 0 && b < n);
}

void dfs(int a, int b, int key) {
	connected[a][b] = key;

	for (int i = 0; i < 4; i++) {
		int dy = a + check[i][0];
		int dx = b + check[i][1];

		if (isInside(dy, dx) && connected[dy][dx] == 1) {
			dfs(dy, dx, key);
		}
	}
}

void Solution(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (connected[i][j] == 1) {
				cnt++;
				dfs(i, j, cnt + 1);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (connected[i][j] > 1) {
				sizeCheck[connected[i][j] - 2]++;
			}
		}
	}

}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &connected[i][j]);
		}
	}
	Solution(n);
	sort(sizeCheck, sizeCheck + cnt);

	printf("%d\n", cnt);

	for (int i = 0; i < cnt; i++) {
		printf("%d\n", sizeCheck[i]);
	}


	return 0;
}