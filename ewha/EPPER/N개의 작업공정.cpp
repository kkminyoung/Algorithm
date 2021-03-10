#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n[],int r[][100],int goal,int N,int R){
	int answer=0;
	
	int indegree[100]={0,};
	int adj[100][100];
	int total[100];
	
	for(int i=0; i<R; i++){
		int x = r[i][0]-1;
		int y = r[i][1]-1;
		adj[x][y]=1;
		indegree[y]++;
	}

	queue<int> q;
	for(int i=0; i<N; i++){
		if(indegree[i]==0){
			total[i] = n[i];
			q.push(i);
		}
	}

	while(!q.empty()){
		int qq = q.front();
		q.pop();
		for(int i=0; i<N; i++){
			if(adj[qq][i]==1){
				total[i] = max(total[i], total[qq] + n[i]);
				indegree[i]--;
				if(indegree[i] == 0) 
					q.push(i);
			}
		}
	}
	
	answer = total[goal-1];
	
	return answer;
}


int main() {
    int N;
    int R;
    int n[100] = {0};
    int r[100][100] = {0};
    int goal, k;

    scanf("%d %d", &N, &R);

    for (int i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }
	
    for (int k = 0; k < R; k++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &r[k][j]);
        }
    }

    scanf("%d", &goal);
    k = solution(n, r, goal, N, R);
    printf("%d\n", k);
}
