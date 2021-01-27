#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
	int answer=s.size();
    
    // 각 단위 돌면서 탐색
	for(int i=1;i<=s.size()/2;i++){ // 반까지만 돌아도 됨!
		string edit; // 압축된 문자열
        string before = s.substr(0,i); // 비교를 위한 이전 문자 
		int cnt=1; // 반복되는 횟수
        
		for(int j=i;j<s.size()+1;j+=i){
			if(before==s.substr(j,i))
                cnt++;
			else{
				if(cnt>1) 
                    edit+=to_string(cnt);
				edit+=before; 
                
				before=s.substr(j,i); // before 업데이트
				cnt=1;
			}
		}
        
		if(cnt>1)
            edit+=to_string(cnt);
		edit+=before;
        
        // 최소값 찾기
		if(answer>edit.size())
			answer=edit.size();
	}
    return answer;
}
