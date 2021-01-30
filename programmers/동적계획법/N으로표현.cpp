#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

// 555, 55, 5 이런식으로 만듬
int get_basic_number(int N, int cnt) {
	int res = 0;
	while (cnt > 0) {
		cnt -= 1;
		res += N * pow(10, cnt);
	}
	return res;
}

int solution(int N, int number) {
	int answer = -1;
	vector<set<int>> s(8);

	int idx = 1;

	for (int i=0; i< s.size(); i++){
		s[i].insert(get_basic_number(N, idx));
		idx += 1;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < i; j++) {
			for (const auto & op1 : s[j]) {
				for (const auto & op2 : s[i - j - 1]) {
					s[i].insert(op1 + op2);
					s[i].insert(op1 - op2);
					s[i].insert(op1 * op2);
					if (op2 != 0)
						s[i].insert(op1 / op2);
				}
			}
		}
        
		if (s[i].find(number) != s[i].end()) {
			answer = i + 1;
			break;
		}
	}
	return answer;
}
