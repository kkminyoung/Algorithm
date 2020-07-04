#include <stdio.h>
#include <stdlib.h>

#define file_len 7 //pdata0.txt~pdata6.txt �� ����
#define TRUE 1
#define FALSE 0
int N;
int M;

typedef struct knapsack {
	int index;
	int pi;
	int wi;
	float pi_wi;
	int X;
}knapsack;

typedef struct element {
	int a, b; // (a,b) ��ǥ
	int value; // ��������� value
	int current_sum; //��������� ��
	float bound; //bound ��
	int *X; // �غ���
}Element;

typedef struct heaptype {
	Element *heap;
	int size;
} HeapType;

knapsack *kanpsack;
HeapType PQ;

void read_file();
void print_file();
void sort();
void queue_init(void);
int is_empty();
void insert(Element node);
Element delete_();
Element bound(int a, int b);
Element best_BB(void);
void print_answer(Element node);

int main(void) {
	read_file(); // ������ �о�� knapsack ����
	sort(); // ���������� �̿��Ͽ� pi/wi ������������ ����
	queue_init(); //queue �ʱ�ȭ
	print_answer(best_BB()); //Best-First Search With Branch&Bound ����� ����Ͽ� �ظ� ���ϰ� �̸� ����Ѵ�.

	return 0;
}

void read_file() {
	FILE *fp;
	fp = fopen("C:/Users/KimMinyoung/Downloads/p2data/p2data0.txt", "r"); // txt ���� �о����
	if (fp == NULL) { // ������ �о���� ���ϴ� ��쿡 ���� ����ó��
		printf("could not read file");
		return;
	}

	// N�о����
	fscanf(fp, "%d", &N);

	kanpsack = (knapsack*)malloc(sizeof(knapsack)*N);

	// index ����
	for (int i = 0; i < N; i++)
		kanpsack[i].index = i;

	// pi �о����
	for (int i = 0; i < N; i++)
		fscanf(fp, "%d ", &kanpsack[i].pi);

	// wi �о����
	for (int i = 0; i < N; i++)
		fscanf(fp, "%d ", &kanpsack[i].wi);

	// pi/wi ���
	for (int i = 0; i < N; i++)
		kanpsack[i].pi_wi = (float)kanpsack[i].pi / (float)kanpsack[i].wi;

	// M �о����
	fscanf(fp, "%d", &M);

	printf("< pr2data0.txt> ");
	print_file();

}

// �Է��� file data�� ����ϴ� �Լ�
void print_file() {

	int i;
	printf("\n");
	printf("N = %d", N);
	printf("\n");
	printf("pi = ");
	for (i = 0; i < N; i++) {
		printf("%d ", kanpsack[i].pi);
	}
	printf("\n");
	printf("wi = ");

	for (i = 0; i < N; i++) {
		printf("%d ", kanpsack[i].wi);
	}
	printf("\n");
	printf("pi/wi = ");

	for (i = 0; i < N; i++) {
		printf("%.1f ", kanpsack[i].pi_wi);
	}
	printf("\n");

	printf("M = %d", M);
	printf("\n");

}

// Insertion Sort �� �̿��Ͽ� ����
void sort() {
	float key_value;
	knapsack key;
	int j;

	for (int i = 1; i < N; i++) {
		key_value = kanpsack[i].pi_wi;
		key = kanpsack[i];

		// ���� �Ϸ� : i-1 ����
		// ���� �̿Ϸ� : i-1 ����

		// key ������ ���ĵ� �迭�� �ִ� ���� ũ�� j��°�� j+1��°�� �̵�
		for (j = i - 1; j >= 0 && kanpsack[j].pi_wi <= key_value; j--) {
			kanpsack[j + 1] = kanpsack[j];
		}
		kanpsack[j + 1] = key;
	}
}





// queue �ʱ�ȭ
void queue_init() {
	PQ.heap = (Element*)malloc(sizeof(Element)*N);
	PQ.size = 0;
}

// ť�� ����ִ��� Ȯ��
// ��������� True, ������� ������ False ��ȯ
int is_empty() {
	if (PQ.size == 0)
		return TRUE;
	else
		return FALSE;
}

// ���� (enqueue) �Լ�
void insert(Element node) {
	Element temp;
	int i = PQ.size;  // queue�� ũ��
	int parent = (i - 1) / 2; // �θ��� �ε��� 
	PQ.heap[i] = node;
	PQ.size++; // queue�� ũ�� ����

	// �ش��ϴ� �κ��� ã�Ƽ� �����Ѵ�.
	while ((PQ.heap[i].value > PQ.heap[parent].value) && (i > 0)) {
		temp = PQ.heap[i];
		PQ.heap[i] = PQ.heap[parent];
		PQ.heap[parent] = temp;

		i = parent;
		parent = (i - 1) / 2;
	}
}

// ���� : dequeue �Լ�
Element delete_() {
	Element result = PQ.heap[0]; //���� �����ִ� ��Ʈ��� ��ȯ�� ���
	Element tmp;
	int i = 0, big = 0, cleft = 1, cright = 2;

	PQ.size--; // �����Ͽ����Ƿ� queue�� ũ�� ����
	PQ.heap[0] = PQ.heap[PQ.size];

	while ((cleft < PQ.size) && (cleft < PQ.size)) {
		// �� ���� �ڽĳ�带 ã�� ����
		if (PQ.heap[cleft].value > PQ.heap[cright].value) {
			tmp = PQ.heap[i];
			PQ.heap[i] = PQ.heap[cleft];
			PQ.heap[cleft] = tmp;
			i = cleft;
		}
		else {
			tmp = PQ.heap[i];
			PQ.heap[i] = PQ.heap[cright];
			PQ.heap[cright] = tmp;
			i = cright;
		}
		cleft = 2 * i + 1; //���� �ڽĳ��
		cright = 2 * i + 2; //������ �ڽĳ��
	}

	if (cright == PQ.size) {
		tmp = PQ.heap[i];
		PQ.heap[i] = PQ.heap[cleft];
		PQ.heap[cleft] = tmp;

		i = cleft;
		cleft = 2 * i + 1; //���� �ڽĳ��
		cright = 2 * i + 2; //������ �ڽĳ��

	}

	return result;
}


//Best First Search With Branch And Bound
Element best_BB(void) {
	int best; // best��
	Element u, v, rnode;
	int i;

	v = bound(0, 0); //(0,0)�� ��Ʈ�� �Ͽ� ���� �ִ´�.
	insert(v);
	best = v.value;

	// Back Tracking ����� ����Ͽ� �ظ� ã�� ����
	while (!is_empty())
	{
		v = delete_();
		for (i = 0; i < 2; i++) {
			u = bound(v.a + 1, 2 * v.b + i);
			if (u.current_sum <= M) {
				// ��ġ�� �ʴ� ��� best���� ������Ʈ �����ش�.
				if (u.value > best) {
					best = u.value;
					rnode = u;
				}
				if (u.bound > best) {
					insert(u);
				}
			}
		}
	}
	rnode.value = best;

	return rnode;
}

//Bound�� ���� ����ϴ� �Լ�
Element bound(int a, int b) {
	int enable_capacity;
	Element node;
	float c;

	node.a = a;
	node.b = b;
	node.X = (int*)malloc(sizeof(int)*a);

	// X�� �ش簪�� ���� 1�� �ְ� �׷��� ������ 0 �� �ִ´�.
	for (int i = 0; i < node.a; i++) {
		node.X[i] = (b >> (node.a - i - 1) & 1);
	}

	node.value = 0;
	node.current_sum = 0;

	for (int i = 0; i < node.a; i++) {
		// �� �ִ� ���
		if (node.X[i] == 1) {
			node.value += kanpsack[i].pi;
			node.current_sum += kanpsack[i].wi;
		}
	}

	int i = node.a;
	node.bound = node.value;
	enable_capacity = M - node.current_sum;

	// bound ���
	while ((enable_capacity > 0) && (i < N)) {
		if (enable_capacity >= kanpsack[i].wi) {
			enable_capacity -= kanpsack[i].wi;
			node.bound += kanpsack[i].pi;
			i++;
		}
		else {
			c = (float)enable_capacity / (float)kanpsack[i].wi;
			enable_capacity = 0; // �� �°� ä���ִ´�.
			node.bound += (float)kanpsack[i].pi * c;
		}
	}
	return node;
}


// ������ ����ϴ� �Լ�
void print_answer(Element node) {
	for (int i = 0; i < N; i++) {
		if (node.X[i] == 1) {
			kanpsack[kanpsack[i].index].X = 1;
		}
		else {
			kanpsack[kanpsack[i].index].X = 0;
		}
	}
	// Maximum profit ���
	printf("\n");
	printf("The maximum profit is $%d", node.value);

	//�غ��� ���
	printf("\nThe solution vector X = (");
	for (int i = 0; i < N - 1; i++) {
		printf("%d, ", kanpsack[i].X);
	}
	printf("%d)\n", kanpsack[N - 1].X);
}