// TRIE 이용해서 다시풀어야함
// 단순 반복문으로 풀었더니 시간초과가 난다.


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> words) {
    int answer = 0;
    
    sort(words.begin(), words.end());
    
    for(int i=0; i<words.size(); i++){
        string curr_word = words[i]; // 찾을 단어
        int curr_count=0;

        bool flag=true;
        for(int c=0; c<curr_word.size(); c++){
            int count = 0;
            for(int j=0; j<words.size(); j++){
                if(flag==true & curr_word[c]==words[j][c]){
                    count ++;
                }
            }
            
            if(count >1)
                curr_count++;
            else
                flag=false;
        }
        if(curr_word.size() != curr_count)
            answer += (curr_count+1);
        
        else
            answer+= curr_count;
        
    }
    
    
    return answer;
}
