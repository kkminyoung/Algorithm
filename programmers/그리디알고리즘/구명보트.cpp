#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	// 사람들 정렬해서 작은애들부터 태울 것임!
	sort(people.begin(), people.end(), greater<int>());

	int left = 0;
	int right = people.size() - 1;

	// 한명씩 태우기~
	while (left < right + 1) {
		if (people[left] + people[right] <= limit) {
			right--;
		}
		left++;
		answer++;
	}

	return answer;
}