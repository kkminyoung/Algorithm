// LCS(Longest Common Subsequence - 최장 공통 부분 수열) 문제

#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(void) {

	// 문자열 입력 받기
	char s1[1001]; //첫번째 문자열
	char s2[1001]; //두번째 문자열
	scanf("%s %s", s1, s2);

	int len1 = strlen(s1);
	int len2 = strlen(s2);

	// 동적계획법
	int dp[1001][1001] = { 0, };
	int i, j, ans = 0;

	for (i = 1; i <= len1; i++) {
		for (j = 1; j <= len2; j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	// 정답 출력
	printf("%d\n", dp[len1][len2]);

	return 0;
}