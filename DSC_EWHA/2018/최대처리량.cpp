#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    int h, m, s;
    int term;
    vector<int> start_t, end_t;
    
    // 시간 분 초 단위를 맞추고 시작, 끝 시간을 찾아내 넣어줌
    for(int i=0; i<lines.size(); i++){
        h = stoi(lines[i].substr(11, 2)) * 3600 * 1000;; // 시간
        m = stoi(lines[i].substr(14, 2)) * 60 * 1000; // 분
        s = stoi(lines[i].substr(17, 2))*1000 + stoi(lines[i].substr(20, 3)) ; // 초
        term = stof(lines[i].substr(24, 5)) * 1000;

        start_t.push_back(h + m + s - term + 1);
        end_t.push_back(h + m + s);
    }
    
    // for문을 돌려 초당 최대 처리량을 구함
    for(int i = 0; i < lines.size(); i++){
        int end_time = end_t[i] + 1000;
        int count = 0;
        
        for(int j = i; j < lines.size(); j++){
            if(start_t[j] < end_time)
                count++;
        }
        
        if(answer < count)
            answer = count;
    }
    
    return answer;
}
