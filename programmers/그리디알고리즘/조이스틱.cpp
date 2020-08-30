#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int my_solution(string name) {
	int answer = 0;
	int curr_idx = 0;

	// AAAA.. �����
	string temp(name.length(), 'A');

	while (true) {
		// ���� �ε��� �ݿ�
		temp[curr_idx] = name[curr_idx];

		// �� ª�� �� ã�� �߰�
		if (name[curr_idx] - 'A' > 'Z' - name[curr_idx] + 1)
			answer += 'Z' + 1 - name[curr_idx];
		else
			answer += name[curr_idx] - 'A';

		// ��� �� �ٲ� ���¶�� break;
		if (temp == name)
			break;
			
		for (int move = 1; move < name.length(); move++) {
			int name_right = name[(curr_idx + move) % name.length()];
			int temp_right = temp[(curr_idx + move) % name.length()];
			int name_left = name[(curr_idx + name.length() - move) % name.length()];
			int temp_left = temp[(curr_idx + name.length() - move) % name.length()];

			// ������ �̵�
			if (name_right != temp_right) {
				curr_idx = (curr_idx + move) % name.length();
				answer += move;
				break;
			}
			// ���� �̵�
			else if (name_left != temp_left) {
				curr_idx = (curr_idx + name.length() - move) % name.length();
				answer += move;
				break;
			}
		}
	}

	return answer;
}

int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

int solution2(string name) {
	int answer = 0;
	for (auto ch : name)
		answer += LUT[ch - 'A'];
	int len = name.length();
	int left_right = len - 1;
	for (int i = 0; i < len; ++i) {
		int next_i = i + 1;
		while (next_i < len && name[next_i] == 'A')
			next_i++;
		// �¿�� ������ �ּ�Ƚ��
		left_right = min(left_right, i + len - next_i + min(i, len - next_i));
	}
	answer += left_right;
	return answer;
}