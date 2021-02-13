#include <string>
#include <vector>

using namespace std;

int answer = 0;

// 4개가 같은지 체크하는 함수
bool check(vector<string> board, int h, int w){
    char c = board[h][w];
    if(c == board[h+1][w] && c == board[h][w+1] && c == board[h+1][w+1])
        return true;
    else
        return false;
}

// 4블록 터트리는 함수
vector<string> update(vector<string> block, int h, int w){
    if(block[h][w]!=' '){
        answer++;
        block[h][w]=' ';
    }
    if(block[h+1][w]!=' '){
        answer++;
        block[h+1][w]=' ';
    }
    if(block[h][w+1]!=' '){
        answer++;
        block[h][w+1]=' ';
    }
    if(block[h+1][w+1]!=' '){
        answer++;
        block[h+1][w+1]=' ';
    }
    
    return block;
}

// 붕떠있는 애들 아래로 내리는 함수
vector<string> down(int m, int n, vector<string> block){
    vector<vector<char>> down_block;
    
    for(int j=0; j<n; j++){
        vector<char> temp;
        for(int i=m-1; i>=0; i--){
            if(block[i][j]!=' ')
                temp.push_back(block[i][j]);
        }
        for(int i=temp.size(); i<m; i++)
            temp.push_back(' ');
        down_block.push_back(temp);
    }
    
    // block에 내린 값을 넣어줌
    for(int i=0; i<down_block.size(); i++){
        for(int j=0; j<down_block[i].size(); j++)
            block[m-j-1][i] = down_block[i][j];
    }

    return block;
}


int solution(int m, int n, vector<string> board) {
    vector<string> block = board;

    // 더이상 터트릴게 없을때까지 반복
    while(true){
        int count = 0;
        for(int i=0; i<m-1; i++){
            for(int j=0; j<n-1; j++){
                if(board[i][j]!=' ' && check(board,i,j)){
                    count++;
                    block = update(block, i, j);
                } 
            }
        }
        block = down(m,n,block);
        board = block;

        if(count==0)
            break;
    }

    return answer;
}
