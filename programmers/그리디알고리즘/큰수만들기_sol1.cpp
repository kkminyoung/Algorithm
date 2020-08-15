#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	int size = number.size();
	int return_size = size - k;

	int max = -1;
	int max_index;
	int index = -1;

	for (int i = 0; i < return_size; i++) {
		for (int j = index + 1; j < size - (return_size - i) + 1; j++) {
			if (max < number[j] - '0') {
				max = number[j] - '0';
				max_index = j;
			}

		}
		answer.append(to_string(max));
		index = max_index;
		max = -1;

	}

	return answer;
}