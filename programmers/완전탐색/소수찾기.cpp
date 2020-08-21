// 문제풀이 방법
// 예전에 백준에서 배웠던 에라토스테네스체 방법 이용해 소수구하기!!

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool *prime_arr;

void prime(int num) {
	// 소수인지를 담을 벡터!!(0이면 소수)
	prime_arr = new bool[num + 1];

	// 에라토스테네스체 이용해 소수 구하기
	// 0,1은 제외!
	prime_arr[0] = false;
	prime_arr[1] = false;

	for (int i = 2; i <= num; i++)
		prime_arr[i] = true;

	for (int i = 2; i*i <= num; i++) {
		if (prime_arr[i])
			for (int j = i * i; j <= num; j += i)
				prime_arr[j] = false;;
	}

}

// string으로 만들 수 있는 숫자 찾기
bool make_num(int num, string str)
{
	// integer -> string
	string strNum = to_string(num);

	for (int i = 0; i < strNum.size(); i++) {
		int flag = false;
		for (int j = 0; j < str.size(); j++) {
			if (strNum.at(i) == str.at(j)) {
				flag = true;
				str.at(j) = ' ';
				break;
			}
		}
		if (!flag)
			return false;
	}
	return true;
}

int solution(string numbers) {
	int answer = 0;

	// 우선 numbers를 내림차순 정렬하여 가장 큰 값을 찾는다!
	sort(numbers.begin(), numbers.end(), greater<int>());
	int num = stoi(numbers); // 스트링을 정수형으로 변환

	prime(num);
	for (int i = 0; i <= num; i++) {
		if (prime_arr[i] && make_num(i, numbers)) {
			answer++;
		}
	}

	return answer;
}