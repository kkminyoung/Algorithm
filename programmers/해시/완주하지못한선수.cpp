#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	// 1. participant, completion 정렬
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	// 2. 없는 사람 찾아서 리턴
	for (int i = 0; i < completion.size(); i++) {
		if (participant[i] != completion[i]) {
			return participant[i];
		}
	}

	// 3. 위에 없는 경우, 마지막 사람!
	return participant.back();
}