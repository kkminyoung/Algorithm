#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> log; 
    map<string, string> id_map; 
    
    // log에 상태, id, 닉네임 저장
    for(int i=0; i<record.size(); i++){
        string current = "";
        vector<string> temp;
        for(int j=0; j<record[i].size(); j++){
            if(record[i][j] == ' '){
                temp.push_back(current);
                current = "";
            }
            else
                current += record[i][j];
        }
        temp.push_back(current);
        log.push_back(temp);
    }
    
    // 아이디별 닉네임 업데이트 (dictionary map)
    for(int i=0; i<log.size(); i++){
        if(log[i][0]=="Enter" || log[i][0] == "Change")
            id_map[log[i][1]] = log[i][2];
    }
    
    // Enter, Leave 기록 answer에 저장
    for(int i=0; i<log.size(); i++){
        if(log[i][0]=="Enter"){
            answer.push_back(id_map[log[i][1]] + "님이 들어왔습니다." );
        }
        else if(log[i][0]=="Leave"){
            answer.push_back(id_map[log[i][1]] + "님이 나갔습니다." );
        }

    }
    
    return answer;
}
