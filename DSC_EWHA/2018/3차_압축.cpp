#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    // 사전 생성
    vector<pair<string, int>> dict;
    for(int i=0; i<26; i++)
        dict.push_back(make_pair(string(1, 'A'+i), i+1));


    // 체크
    string txt_check = "";
    txt_check+=msg[0];
    int curr_idx;
    for(int i=1; i<msg.size(); i++){
        for(int j=0; j<dict.size();j++){
            if(txt_check==dict[j].first){
                curr_idx = j+1;
                break;
            }
        }
        
        txt_check += msg[i];
    
        bool isIn = false;
        for(int j=0; j<dict.size(); j++){
            if(txt_check==dict[j].first){
                isIn=true;
                curr_idx = j+1;
                break;
            }
        }
        
        if(isIn==false){
            dict.push_back(make_pair(txt_check,dict.size()));
            answer.push_back(curr_idx);
            txt_check = msg[i];
        }
    }
    
    // 마지막 글자처리
    for(int j=0; j<dict.size();j++){
        if(txt_check==dict[j].first){
            curr_idx = j+1;
            break;
        }
    }
    answer.push_back(curr_idx);
    
    return answer;
}
