#include <string>
#include <vector>
 
using namespace std;
 
bool flag[50] = {false}; // 방문했음을 알리는 flag
int answer = 50; // 가장 짧은 길이
 
// 알파벳 하나만 다른지
bool diff_count(string a, string b){
    int diff=0;
    for(int i=0 ; i<a.size(); i++){
        if(a[i]!=b[i])
            diff++;
    }
    return (diff==1);
}

// dfs
void dfs(string begin, string target, vector<string> words,bool * flag, int count){
    for(int i = 0 ; i<words.size(); i++){
        if(diff_count(begin,words[i])){ //단어 하나만 다른 경우
            if(target==words[i]){ //정답인 경우
                // 가장 짧은 변환을 정답으로 대체
                if(answer> count+1){
                    answer = count+1;
                    return;
                }
            }
            // 방문하지 않은 경우
            if(!flag[i])  {
                flag[i] = true; // 방문 표시
                dfs(words[i],target,words,flag,count+1);
            }
        }
    }
}
 
int solution(string begin, string target, vector<string> words) {
    dfs(begin,target,words,flag,0);
    if(answer==50)
        answer = 0;
    return answer;
}
