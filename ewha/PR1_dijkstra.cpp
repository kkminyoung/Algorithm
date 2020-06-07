// 1829008 김민영
// computer algorithm 
// Programing Report1 : 다익스트라 알고리즘

#include <stdio.h>
#define INF 9999; // Edge가 없는 경우의 가중치

int W[101][1001]; // adjacent Matrix
int F[101]; // edge set of shortest path tree rooted at Start
int length[101]; // 집합 F에서 각 vertex까지의 길이
int vnear = 0;
int n;

// 파일을 읽어와 adjacent Matrix W를 만든다.
void read_adjacentM() {
	FILE *fp;
	int m;
	fp = fopen("C:/Temp/PR1_data/graph6.txt", "r"); // txt 파일 읽어오기
	if (fp == NULL) { // 파일을 읽어오지 못하는 경우에 대한 예외처리
		printf("could not read file");
		return;
	}
	printf("< graph6.txt >\n");

	fscanf(fp, "%d", &n);
	fscanf(fp, "%d", &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			W[i][j] = INF;
		}
	}

	// 대각선 0으로
	for (int i = 1; i <= n; i++) {
		W[i][i] = 0;
	}

	// weight 초기화
	for (int i = 1; i <= m; i++) {
		int node1, node2, weight;
		fscanf(fp, "%d", &node1);
		fscanf(fp, "%d", &node2);
		fscanf(fp, "%d", &weight);
		W[node1][node2] = weight;
	}
}

// adjacent Matrix 출력
void print_adjacentM() {
	printf("Adjacency Matrix\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%5d", W[i][j]);
			//or printf("%d\t",W[i][j]);
		}
		printf("\n");
	}
}

// 다익스트라 알고리즘
void dijkstra(int n, int W[][1001], int F[], int start) {
	int min;
	// int touch[101];

	// length에 start vertex에서 해당 vertex 까지의 길이를 저장해놓는다
	for (int i = 1; i <= n; i++) {
		if (i != start) {
			// touch[i]= 1;
			length[i] = W[start][i];
		}
	}
	// start vertex에서 start vertex 사이의 거리는 0이다.
	F[start - 1] = 0;


	// vnear : 다음에 방문할 가까운 vertex
	for (int i = 1; i < n; i++) {
		min = INF;
		for (int i = 1; i <= n; i++) {
			if (i != start) {
				if (0 <= length[i] && length[i] < min) {
					min = length[i];
					vnear = i;
				}
			}
		}

		// touch , length의 변화값 수정
		for (int i = 1; i <= n; i++) {
			if ((i != start) && (W[vnear][i] != 9999)) {
				if (length[vnear] + W[vnear][i] < length[i]) {
					length[i] = length[vnear] + W[vnear][i];
					//touch[i] = vnear;
				}
			}
		}

		// 방문한 vertex 값 min을 F에 저장하고 length에는 방문했음에 대한 표시로 -1을 저장한다.
		F[vnear - 1] = min;
		length[vnear] = -1;
	}


	// 출력
	printf("Shortest paths from v%d = ", start);
	printf("( ");
	for (int i = 0; i < n; i++) {
		printf("%d ", F[i]);
	}
	printf(")");
	printf("\n");
}



int main(void) {
	read_adjacentM();
	print_adjacentM();

	printf("\n");

	// start vertex 지정
	for (int start = 1; start <= n; start++) {
		dijkstra(n, W, F, start);
	}

	return 0;
}