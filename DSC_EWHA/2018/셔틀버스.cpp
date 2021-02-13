#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> time;
    
    // 먼저온 순서대로 정렬
    sort(timetable.begin(), timetable.end());
    
    // 시간 -> 분으로 단위 맞춰줌
    for(int i=0; i<timetable.size(); i++){
        int t = stoi(timetable[i].substr(0,2))*60 + stoi(timetable[i].substr(3,2));
        time.push_back(t);
    }
    
    
    int ans = 0; // 정답시간
    int bus = 540; // 버스 출발시간
    int idx = 0; // 크루원 타임테이블 하나씩 탐색할 인덱스
    
    // 버스 대수만큼 반복
    for (int i = 0; i < n; i++) {
		int people = 0;
        
        // 해당 버스에 들어갈 수 있는 만큼 넣음
		for(int j = idx;j<time.size();j++){
			if (time[idx] <= bus) { // 버스 출발시간보다 빨리 왔으면 넣음
				idx++;
				people++;
			}
			if (people == m) 
                break;
		}

        // 마지막 버스일경우 정답처리해줌
		if (i == n - 1) {
			if (people == m)  // 버스가 꽉 찼다면 마지막 사람의 -1 한 시간
                ans = time[idx-1]-1;
			else // 꽉 차지 않았다면 마지막 버스의 시간
                ans = bus;
		}
        
		bus += t;
        
        // 밤 11시 59분이후 끝
		if (bus>= 24*60) 
            break;
	}
    
    

    // 시간을 텍스트로 반환해줌
    
    int hour = ans/60;
    int min = ans%60;
    
    if(hour<10) answer+="0"+to_string(hour);
    else answer+=to_string(hour);
    
    answer+=":";
    
    if(min<10) answer +="0"+to_string(min);
    else answer+=to_string(min);
    
    return answer;
}
