#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int connected[50][50];
int mat[50][50];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int T, M, N, K;


int answer;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}


void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;

		if (mat[ny][nx] && !connected[ny][nx]) {
			connected[ny][nx]++;
			dfs(ny, nx);
		}
	}
}

void Solution() {
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mat[i][j] && !connected[i][j]) {
				answer++;
				connected[i][j]++;
				dfs(i, j);
			}
		}
	}
	cout << answer << endl;

}

int main() {
	cin >> T;

	for (int t = 0; t < T; t++) {
		init();
		cin >> M >> N >> K; 

		memset(mat, 0, sizeof(mat));
		memset(connected, 0, sizeof(connected));

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			mat[y][x] = 1;
		}

		Solution();

	}
	return 0;
}
