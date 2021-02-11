#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int inner_count = 0;
    int outer_count = 0;
    vector<string> v1;
    vector<string> v2;
    
    // 모두 대문자로 변환
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);     
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);  
    
    // 알파벳만 v1에 담음
    for(int i=0; i<str1.size()-1; i++){
        string slice = str1.substr(i,2);
        if(slice[0] >='A' && slice[0] <= 'Z' && slice[1] >='A' && slice[1] <='Z') 
            v1.push_back(slice);
    }
    
    // 알파벳만 v2에 담음
    for(int i=0; i<str2.size()-1; i++){
        string slice = str2.substr(i,2);
        if(slice[0] >= 'A' && slice[0] <= 'Z' && slice[1] >= 'A' && slice[1] <= 'Z') 
            v2.push_back(slice);
    }
    
    int size = v1.size() + v2.size();

    // 교집합 계산
    for(int i=0; i<v1.size(); i++){
        for(int j=0; j<v2.size(); j++){
            if(v1[i]==v2[j]){
                inner_count++;
                v2[j]= " ";
                break;
            }
        }
    }
    
    // 합집합 계산
    outer_count = size - inner_count;
    
    
    // 정답처리 : 교집합/합집합
    if(outer_count==0)
        answer=65536;
    else
        answer = inner_count* 65536 / outer_count;
    
    
    return answer;
}
