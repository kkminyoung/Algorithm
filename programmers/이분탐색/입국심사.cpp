#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long min = 1;
	long long max;
	long long average;
	long long human = 0;

	// 최댓값
	max = *max_element(times.begin(), times.end())*(long long)n;

	// 이분탐색 방법 이용
	while (min <= max) {
		average = ((max + min) / 2);
		for (auto t : times)
			human += average / t;
		if (n <= human) {
			answer = average;
			max = average - 1;
		}
		else
			min = average + 1;
		human = 0;
	}

    return answer;
}