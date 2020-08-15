#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	// 학생별 체육복 갯수를 담을 벡터!! 1로 초기화
	vector<int> student(n,1);

	// lost 학생의 경우, --
	for (int i = 0; i < lost.size(); i++) 
		student[lost[i] - 1]--;
	
	// reserve 학생의 경우 ++
	for (int i = 0; i < reserve.size(); i++) 
		student[reserve[i] - 1]++;
	
	// 체육복 빌려주기!!
	for (int i = 0; i < student.size(); i++) {
		// 첫번째 사람 아니고, 앞사람 옷이 없으면
		if (i != 0 && student[i - 1] == 0) {
			// 옷 나눠줄 수 있는 사람
			if (student[i] == 2) {
				student[i - 1]++;
				student[i]--;
			}
		}
		// 마지막 사람이 아니고, 뒷사람 옷이 없으면
		if (i != student.size() - 1 && student[i + 1] == 0) {
			// 옷 나눠줄 수 있는 사람
			if (student[i] == 2) {
				student[i + 1]++;
				student[i]--;
			}
		}	
	}

	// answer에 저장
	for (int i = 0; i < student.size(); i++) {
		if (student[i]>=1)
			answer++;
	}

	return answer;
}