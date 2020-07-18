#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

vector<pair<int, int>> timeTable; // 회의시간(시작,끝) 담을 벡터

int N; // 회의의 수

int main(void) {
	int start; //회의의 시작시간
	int end; //회의의 끝나는 시간
	int check[1000001];

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &start, &end);
		timeTable.push_back({ end,start });
	}

	sort(timeTable.begin(), timeTable.end()); // 회의시간 정렬


	// greedy approach
	int max_result = 0; // 최대 사용할 수 있는 회의의 개수
	int time = 0;
	for (int i = 0; i < N; i++) {
		if (timeTable[i].second >= time) {
			max_result++;
			time = timeTable[i].first;
		}
	}

	// 결과값 출력
	printf("%d", max_result);

	return 0;
}