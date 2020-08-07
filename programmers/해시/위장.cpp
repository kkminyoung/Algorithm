#include <string>
#include <vector>
#include <map> 

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	// 해시를 이용하여 풀이
	map <string, int> hash;

	// 옷 분류마다 종류 count 찾기
	for (vector<string> pair : clothes) {
		hash[pair[1]]++;
	}
	// sol2
	// for(int i=0; i<clothes.size();i++){
	//     hash[clothes[i][1]]++;
    // }

	// 반복자
	map <string, int>::iterator iter;

	// 옷 분류1 x ... x 옷 분류 n
	for (iter = hash.begin(); iter != hash.end(); iter++) {
		int c = iter->second + 1;
		answer *= c;
	}

	// 옷을 아예 입지 않는 경우의 수는 제외하므로 -1
	return answer - 1;
}