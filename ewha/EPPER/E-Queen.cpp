#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> col(15);
vector<vector<int>> unable(15, vector<int>(15));

int N, total = 0;

bool check(int level){
    for(int i = 0; i < level; i++){
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i) // 대각선이거나 같은 라인 제외
            return false;
    }
    return true;
}

void nqueen(int x){
    if(x == N){
        total++;
        return;
    }
    else{
        for(int i = 0; i < N; i++){
            col[x] = i; // 해당 위치에 퀸을 배치 
            if(check(x) && !unable[x][i])
                nqueen(x+1);
        }
    }
}

int solution(int n, int k, vector<int> &X, vector<int> &Y){
    int answer = 0;
    N = n;
        
    for (int i = 0; i < k; i++)
        unable[X[i] - 1][Y[i] - 1] = 1;
	
    nqueen(0);
    answer = total;
	
    return answer;
}


 int main(void) {
    int n,k;
        
    cin >> n;
    cin >> k;

    vector<int> vX;
    vector<int> vY;

    string str;
    for(int i=0; i<k; i++){
        cin >> str;
        string num="";
        for(int j=0; j<str.size(); j++){
            if(str[j] >='0' && str[j] <='9')
                num += str[j];
        }
        vX.push_back(stoi(num));
    }
	
    for(int i=0; i<k; i++){
        cin >> str;
        string num ="";
        for(int j=0; j<str.size(); j++){
            if(str[j] >='0' && str[j] <='9')
                num += str[j];
        }
        vY.push_back(stoi(num));
    }
    cout << solution(n, k, vX, vY);

    return 0;
}
