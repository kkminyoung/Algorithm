#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    vector<int> v;
    string number ="";
    int num = 0;
    
    for(int i=0; i<dartResult.size(); i++){
        // 숫자 처리
        if(dartResult[i]>='0' && dartResult[i]<='9')
            number += dartResult[i];
        
        // 옵션 처리
        else if(dartResult[i]=='*'){
            v[v.size()-1] *=2;
            v[v.size()-2] *=2;
        }
        else if(dartResult[i]=='#'){
             v[v.size()-1] = num*(-1);
        }
        
        // S, D, T 처리
        else{
            num = stoi(number);
            
            if(dartResult[i]=='S') num = num;
            else if(dartResult[i]=='D') num = num * num;
            else if(dartResult[i]=='T') num = num * num * num;
            
            v.push_back(num);
            number = "";
        }
    }
    
    // 정답처리
    for(int i=0; i<v.size(); i++)
        answer += v[i];
    
    return answer;
}
