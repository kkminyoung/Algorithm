#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool check[8]; 
set<string> answer_set; 

void dfs(vector<string> u_id, vector<string> b_id, int b_ind){
    int b_size = b_id.size();
    int u_size = u_id.size();

    // 탈출
    if(b_ind >= b_size){
        string temp = "";
        for(int i=0; i<u_id.size(); i++){
            if(check[i]){
                temp += i;
            }
        }
        answer_set.insert(temp);
        return;
    }
    
    
    for (int i = 0; i < u_size; i++) {
        bool tmp = true;
        
        // 사이즈가 다르거나 이미 사용한 경우 제외
	if (b_id[b_ind].size() != u_id[i].size() || check[i]) {
		continue;
	}
        
        // banned_id가 될 수 있는지
	for (int j = 0; j < u_id[i].size(); j++) {
		if (b_id[b_ind][j] == '*') {
			continue;
		}

                // 글자가 다른 경우 false로
		if (u_id[i][j] != b_id[b_ind][j]) {
			tmp = false;
			break;
		}
	}

        // 가능한 경우라면 
	if (tmp) {
		check[i] = true;
		dfs(u_id, b_id, b_ind + 1);
		check[i] = false;
	}
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(user_id, banned_id, 0);
	int answer = answer_set.size();
	return answer;
}
