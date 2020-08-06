#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	// 1. participant, completion ����
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	// 2. ���� ��� ã�Ƽ� ����
	for (int i = 0; i < completion.size(); i++) {
		if (participant[i] != completion[i]) {
			return participant[i];
		}
	}

	// 3. ���� ���� ���, ������ ���!
	return participant.back();
}