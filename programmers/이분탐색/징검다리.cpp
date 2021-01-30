#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    
    
    // 몇으로 제거할건지 적당한 거리를 이분탐색
    int left = 1;
    int right = distance;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        int remove = 0;
        
        int idx = -1;
        for (int i = 0; i <= rocks.size(); i++) {
            int d;
            if(idx==-1)
                d = rocks[i];
            else{
                if(i == rocks.size())
                    d = distance-rocks.back();
                else
                    d = rocks[i]-rocks[idx];
            }
            
            
            if (d < mid) 
                remove++;
            else 
                idx = i;
        }
        
        // 제거를 너무 많이 해버린 경우 : 적은 거리로 탐색
        if (remove > n) 
            right = mid - 1;
        // 제거를 적게 한 경우 : 넓은 거리로 탐색
        else if (remove <= n) {
            left = mid + 1;
            if(answer < mid)
                answer = mid;
        }
    }
    
    return answer;
}
