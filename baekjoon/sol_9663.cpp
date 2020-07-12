// N-Queen 문제 (Backtracking)

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int col[16];
int n;
int result = 0;

// promising function
// 1. column 체크(col[i] == col[k]), 2. 대각선 체크(abs(col[i] - col[k]) == i - k)
bool promising(int i) {
	int k=1; // index
	bool s = true; //switch
	while (k < i && s) {
		if (col[i] == col[k] || abs(col[i] - col[k]) == i - k)
			s = false;
		k++;
	}
	return s;
}

void queens(int i) {
	int j;
	if (promising(i)) {
		if (i == n)
			result += 1;
		else {
			for (j = 1; j <= n; j++) {
				col[i + 1] = j;
				queens(i + 1);
			}
		}

	}
}




int main(void) {
	scanf("%d", &n);
	queens(0);
	printf("%d", result);

	return 0;
}