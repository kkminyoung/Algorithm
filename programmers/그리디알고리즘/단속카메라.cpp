#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1; // 카메라 대수
	// 정렬
	sort(routes.begin(), routes.end());
	// 처음 차가 나가는 부분
	int curr = routes[0][1];

	for (auto a : routes) {
		// 겹치는 부분 안 생긴다면 카메라 설치
		if (curr < a[0]) {
			answer++; // 카메라 대수 증가
			curr = a[1]; // 나가는 부분 업데이트
		}
		// 겹치는 부분 생긴다면
		if (curr >= a[1])
			curr = a[1]; // 카메라 설치하지 않고 나가는 부분 업데이트만
	}
	return answer;
}