// 2017 카카오 코드
#include <vector>

using namespace std;

int bfs(int m, int n, int x, int y, vector<vector<int>>& picture, int target){
    // 종료조건
    if(x < 0 || y < 0 || x == m || y == n || target != picture[x][y])
        return 0;
    
    // 방문했음을 표시
    picture[x][y] = -1; 
    
    // 사방으로 탐색
    int up = bfs(m, n, x - 1, y, picture, target);
    int down = bfs(m, n, x + 1, y, picture, target);
    int left = bfs(m, n, x, y - 1, picture, target);
    int right = bfs(m, n, x, y + 1, picture, target);
    
    return up + down + left + right + 1;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {    
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(picture[i][j] == 0 || picture[i][j] == -1)
                continue;
            else{
                number_of_area++;
                int tmp  = bfs(m, n, i, j, picture, picture[i][j]);
                max_size_of_one_area = max(tmp, max_size_of_one_area);
            }
        }
    }
    
    vector<int> answer(2);
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}
