#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	// �л��� ü���� ������ ���� ����!! 1�� �ʱ�ȭ
	vector<int> student(n,1);

	// lost �л��� ���, --
	for (int i = 0; i < lost.size(); i++) 
		student[lost[i] - 1]--;
	
	// reserve �л��� ��� ++
	for (int i = 0; i < reserve.size(); i++) 
		student[reserve[i] - 1]++;
	
	// ü���� �����ֱ�!!
	for (int i = 0; i < student.size(); i++) {
		// ù��° ��� �ƴϰ�, �ջ�� ���� ������
		if (i != 0 && student[i - 1] == 0) {
			// �� ������ �� �ִ� ���
			if (student[i] == 2) {
				student[i - 1]++;
				student[i]--;
			}
		}
		// ������ ����� �ƴϰ�, �޻�� ���� ������
		if (i != student.size() - 1 && student[i + 1] == 0) {
			// �� ������ �� �ִ� ���
			if (student[i] == 2) {
				student[i + 1]++;
				student[i]--;
			}
		}	
	}

	// answer�� ����
	for (int i = 0; i < student.size(); i++) {
		if (student[i]>=1)
			answer++;
	}

	return answer;
}