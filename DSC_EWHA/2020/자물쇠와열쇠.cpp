#include <string>
#include <vector>

using namespace std;

//회전
vector<vector<int>> rotate(vector<vector<int>> key){
    int s = key.size();
    vector<vector<int>> result(s, vector<int>(s, 0));

    for (int a = 0; a < s; a++){
        for(int i = s-1, b = 0; i >= 0 ; i--, b++){
            result[a][b] = key[i][a];
        }
    }
    return result;
}

// insert 후 확인
int insert (int x, int y, int N, vector<vector<int>> board, vector<vector<int>> key){
    int M = key.size();

    for(int ny = y, a = 0; ny < y + M; ny++, a++){
        for(int nx = x, b = 0; nx < x + M; nx++, b++) {
            board[ny][nx] = board[ny][nx] ^ key[a][b];
            if(!board[ny][nx] && key[a][b]) 
                return -1; // 다른경우
        }
    }

    //해당 자물쇠가 다 들어맞았는지 count
    int count = 0;
    for(int ny = M-1; ny < M+N-1; ny++){
        for(int nx = M-1; nx <  N+M-1; nx++){
            if(!board[ny][nx]) 
                count ++;
        }
    }
    return count;

}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int N = lock.size(), M = key.size();
    vector<vector<int>> board(2*M+N-2, vector<int>(2*M+N-2, 0));

    // board에 lock 세팅
    for(int ny = M-1, a = 0; ny < M-1 + N; ny++, a++){
        for(int nx = M-1, b = 0; nx < M-1 + N; nx++, b++) {
            board[ny][nx] = lock[a][b];
        }
    }

    // board에 회전하며 key 세팅
    for(int i = 0; i < M+N-1; i++){
        for (int l = 0; l < M+N-1; l++){
            vector<vector <int>> nextKey = key;

            for(int d = 0; d < 4; d++)
            {
                if(insert(l, i, N, board, nextKey) == 0) return true;
                nextKey = rotate(nextKey);
            }
        }
    }
    return false;
}
