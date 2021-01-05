#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    
    // moves에 담겨있는 숫자들 하나씩 처리
    for(int i=0; i<moves.size(); i++){
        int idx = moves[i]-1;
        // 제일 위에 있는 인형을 집음(처음으로 0이 아닌 것)
        for(int j=0; j<board.size(); j++){
            int val = board[j][idx];
            if(val!=0){
                board[j][idx]=0;
                // 같은 종류의 인형이면 터트림
                if(!basket.empty() && val==basket.top()){
                    answer+=2;
                    basket.pop();
                }
                else
                    basket.push(val);
                break;
            }
        }
    }
  
    return answer;
}
