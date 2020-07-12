// LCS(Longest Common Subsequence - ���� ���� �κ� ����) ����

#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(void) {

	// ���ڿ� �Է� �ޱ�
	char s1[1001]; //ù��° ���ڿ�
	char s2[1001]; //�ι�° ���ڿ�
	scanf("%s %s", s1, s2);

	int len1 = strlen(s1);
	int len2 = strlen(s2);

	// ������ȹ��
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

	// ���� ���
	printf("%d\n", dp[len1][len2]);

	return 0;
}