// ����Ǯ�� ���
// ������ ���ؿ��� ����� �����佺�׳׽�ü ��� �̿��� �Ҽ����ϱ�!!

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool *prime_arr;

void prime(int num) {
	// �Ҽ������� ���� ����!!(0�̸� �Ҽ�)
	prime_arr = new bool[num + 1];

	// �����佺�׳׽�ü �̿��� �Ҽ� ���ϱ�
	// 0,1�� ����!
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

// string���� ���� �� �ִ� ���� ã��
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

	// �켱 numbers�� �������� �����Ͽ� ���� ū ���� ã�´�!
	sort(numbers.begin(), numbers.end(), greater<int>());
	int num = stoi(numbers); // ��Ʈ���� ���������� ��ȯ

	prime(num);
	for (int i = 0; i <= num; i++) {
		if (prime_arr[i] && make_num(i, numbers)) {
			answer++;
		}
	}

	return answer;
}