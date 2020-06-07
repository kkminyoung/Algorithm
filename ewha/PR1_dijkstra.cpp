// 1829008 ��ο�
// computer algorithm 
// Programing Report1 : ���ͽ�Ʈ�� �˰���

#include <stdio.h>
#define INF 9999; // Edge�� ���� ����� ����ġ

int W[101][1001]; // adjacent Matrix
int F[101]; // edge set of shortest path tree rooted at Start
int length[101]; // ���� F���� �� vertex������ ����
int vnear = 0;
int n;

// ������ �о�� adjacent Matrix W�� �����.
void read_adjacentM() {
	FILE *fp;
	int m;
	fp = fopen("C:/Temp/PR1_data/graph6.txt", "r"); // txt ���� �о����
	if (fp == NULL) { // ������ �о���� ���ϴ� ��쿡 ���� ����ó��
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

	// �밢�� 0����
	for (int i = 1; i <= n; i++) {
		W[i][i] = 0;
	}

	// weight �ʱ�ȭ
	for (int i = 1; i <= m; i++) {
		int node1, node2, weight;
		fscanf(fp, "%d", &node1);
		fscanf(fp, "%d", &node2);
		fscanf(fp, "%d", &weight);
		W[node1][node2] = weight;
	}
}

// adjacent Matrix ���
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

// ���ͽ�Ʈ�� �˰���
void dijkstra(int n, int W[][1001], int F[], int start) {
	int min;
	// int touch[101];

	// length�� start vertex���� �ش� vertex ������ ���̸� �����س��´�
	for (int i = 1; i <= n; i++) {
		if (i != start) {
			// touch[i]= 1;
			length[i] = W[start][i];
		}
	}
	// start vertex���� start vertex ������ �Ÿ��� 0�̴�.
	F[start - 1] = 0;


	// vnear : ������ �湮�� ����� vertex
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

		// touch , length�� ��ȭ�� ����
		for (int i = 1; i <= n; i++) {
			if ((i != start) && (W[vnear][i] != 9999)) {
				if (length[vnear] + W[vnear][i] < length[i]) {
					length[i] = length[vnear] + W[vnear][i];
					//touch[i] = vnear;
				}
			}
		}

		// �湮�� vertex �� min�� F�� �����ϰ� length���� �湮������ ���� ǥ�÷� -1�� �����Ѵ�.
		F[vnear - 1] = min;
		length[vnear] = -1;
	}


	// ���
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

	// start vertex ����
	for (int start = 1; start <= n; start++) {
		dijkstra(n, W, F, start);
	}

	return 0;
}