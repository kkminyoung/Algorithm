#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i=0; i<skill_trees.size(); i++){
        int count = 0;
        int flag = 0;
        
        for(int j=0; j<skill_trees[i].size(); j++){
            for(int c=0; c<skill.size(); c++){
                if(skill_trees[i][j]==skill[c]){
                    if(count!=c){
                        flag=1;
                        break;
                    }
                    count++;
                }
            }
        }
        if(flag==0){
            answer++;
        }
    }
    return answer;
}
