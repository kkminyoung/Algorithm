#include <string>
#include <vector>
#include <map> 

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	// �ؽø� �̿��Ͽ� Ǯ��
	map <string, int> hash;

	// �� �з����� ���� count ã��
	for (vector<string> pair : clothes) {
		hash[pair[1]]++;
	}
	// sol2
	// for(int i=0; i<clothes.size();i++){
	//     hash[clothes[i][1]]++;
    // }

	// �ݺ���
	map <string, int>::iterator iter;

	// �� �з�1 x ... x �� �з� n
	for (iter = hash.begin(); iter != hash.end(); iter++) {
		int c = iter->second + 1;
		answer *= c;
	}

	// ���� �ƿ� ���� �ʴ� ����� ���� �����ϹǷ� -1
	return answer - 1;
}