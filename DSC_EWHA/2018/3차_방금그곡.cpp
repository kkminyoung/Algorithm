#include <string>
#include <vector>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int max_time=0;
 
    for(int i=0; i<musicinfos.size(); i++){
        
        // 재생시간 계산
        int start_time = stoi(musicinfos[i].substr(0,2))*60 + stoi(musicinfos[i].substr(3,2));
        int end_time = stoi(musicinfos[i].substr(6,2))*60 + stoi(musicinfos[i].substr(9,2));
        int time = end_time - start_time;
        
        
        // 곡명, 음 저장
        string name;
        string music;
        int flag=0;
        for(int j=12; j<musicinfos[i].size(); j++){
            if(musicinfos[i][j]==','){
                flag=1;
                continue;
            }
            else if(flag==0)
                name += musicinfos[i][j];
            
            else if(flag==1)
                music += musicinfos[i][j];
            
        }
        
        // 음 벡터에 저장
        vector<string> m_v;
        for(int j=0; j<music.size();j++){
            if(music[j]=='#'){
                m_v.erase(m_v.begin()+m_v.size()-1);
                m_v.push_back(music.substr(j-1,2));
            }
            else
                m_v.push_back(music.substr(j,1));
        }
        
        // 곡을 벡터로 저장
        vector<string> mm;
        for(int j=0; j<m.size();j++){
            if(m[j]=='#'){
                mm.erase(mm.begin()+mm.size()-1);
                mm.push_back(m.substr(j-1,2));
            }
            else
                mm.push_back(m.substr(j,1));
        }
        

        // 재생할 음 벡터로 저장
        int m_size = m_v.size();
        vector<string> play_v;
        for(int j=0; j<time; j++){
            play_v.push_back(m_v[j%m_size]);
        }
    
        
        // 같은지 체크
        bool isIn = false;
        int check = time - mm.size();
        
        for(int a=0; a <= check; a++){
            int isSame = 0;
            for(int b=0; b < mm.size(); b++){
                if(mm[b]!=play_v[a+b])
                    isSame=1;
            }
            
            if(isSame==0){ 
                isIn=true;
                break;
            }
            
            
        }
        
        // 정답 곡 저장(같은게 있으면 재생시간 가장 큰놈)
        if(isIn==true && time > max_time){
            answer = name;
            max_time = time;
        }
            

    }
    
    if(answer=="")
        answer="(None)";
    
    return answer;
}
