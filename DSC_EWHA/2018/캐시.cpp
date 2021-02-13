#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> queue;
    
    for(int i=0;i<cities.size();i++){
        string city = cities[i];
        
        // 대문자,소문자 구분 x
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        // 있는지 체크
        bool check = false;
        int idx;
        for(int j=0;j<queue.size();j++){
            if(city == queue[j]){
                check = true;
                idx = j;
            }
        }
        
        // 있는경우
        if(check == true){ 
            answer++; 
            queue.erase(queue.begin()+idx);
            queue.push_back(city);
        }
        // 없는 경우
        else{ 
           answer+=5; 
            if(cacheSize != 0){
                if(queue.size() == cacheSize){
                    queue.erase(queue.begin());
                }
                queue.push_back(city);
            }
        }
    }
    return answer;
}
