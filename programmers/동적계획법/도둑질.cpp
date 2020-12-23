#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int size = money.size();
    
    // 첫번째부터 시작, 두번째부터 시작 나누어 작성
    int first[size];
    int second[size];
    
    // 초기값 세팅
    first[0]=money[0];
    first[1]=money[0];
    second[0]=0;
    second[1]=money[1];
    
    // 동적계획법 사용
    for (int i = 2; i <= size - 2; i++)
		first[i] = max(first[i - 2] + money[i],first[i - 1]);
    
    for (int i = 2; i  <= size - 1; i++)
		second[i] = max(second[i - 2] + money[i], second[i - 1]);
    
    // 첫번째부터 시작한 최대값과 두번째부터 시작한 최대값 비교하여 더 큰게 최대값
    answer = max(first[size  - 2], second[size - 1]);
    return answer;
}
