#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	// 1. 앞에서 부터 비교할 것이기 때문에 작은 순서로 정렬!
	sort(phone_book.begin(), phone_book.end());

	// 2. 비교
	for (int i = 0; i < phone_book.size() - 1; i++) {
		if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
			return false;
	}

	return answer;
}