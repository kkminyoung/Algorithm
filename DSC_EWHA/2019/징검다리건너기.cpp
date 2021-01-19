// 문제를 보자마자 완전탐색으로 쉽게 풀었으나, 효율성테스트가 포함되어있는 문제였어서 낮은 점수를 받았다.
// 그래서 이분탐색으로 다시 풀었다.

#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// 이분탐색
// 이분탐색 기준 : 징검다리 건너는 사람의 수 
bool binary_search(int& n, int& k, vector<int>& v){
    int count = 0;
    
    for(int i = 0; i < v.size(); i++){
        if(v[i] - n <= 0)
            count++;
        else
            count = 0;
            
        // 불가능한 경우    
        if(count >= k)
            return true;
    }
    return false;
}
 
int solution(vector<int> stones, int k) {
    // 돌멩이 숫자의 최대, 최소
    int first = 1, last = *max_element(stones.begin(), stones.end());
    
    // 
    while(first <= last){
        int mid = (first + last) / 2;
        if(binary_search(mid, k, stones))
            last = mid - 1;
        else
            first = mid + 1;
    }
    
    return first;
}
