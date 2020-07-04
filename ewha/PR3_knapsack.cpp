#include <stdio.h>
#include <stdlib.h>

#define file_len 7 //pdata0.txt~pdata6.txt 의 갯수
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
	int a, b; // (a,b) 좌표
	int value; // 현재까지의 value
	int current_sum; //현재까지의 합
	float bound; //bound 값
	int *X; // 해벡터
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
	read_file(); // 파일을 읽어와 knapsack 저장
	sort(); // 삽입정렬을 이용하여 pi/wi 내림차순으로 정렬
	queue_init(); //queue 초기화
	print_answer(best_BB()); //Best-First Search With Branch&Bound 방법을 사용하여 해를 구하고 이를 출력한다.

	return 0;
}

void read_file() {
	FILE *fp;
	fp = fopen("C:/Users/KimMinyoung/Downloads/p2data/p2data0.txt", "r"); // txt 파일 읽어오기
	if (fp == NULL) { // 파일을 읽어오지 못하는 경우에 대한 예외처리
		printf("could not read file");
		return;
	}

	// N읽어오기
	fscanf(fp, "%d", &N);

	kanpsack = (knapsack*)malloc(sizeof(knapsack)*N);

	// index 지정
	for (int i = 0; i < N; i++)
		kanpsack[i].index = i;

	// pi 읽어오기
	for (int i = 0; i < N; i++)
		fscanf(fp, "%d ", &kanpsack[i].pi);

	// wi 읽어오기
	for (int i = 0; i < N; i++)
		fscanf(fp, "%d ", &kanpsack[i].wi);

	// pi/wi 계산
	for (int i = 0; i < N; i++)
		kanpsack[i].pi_wi = (float)kanpsack[i].pi / (float)kanpsack[i].wi;

	// M 읽어오기
	fscanf(fp, "%d", &M);

	printf("< pr2data0.txt> ");
	print_file();

}

// 입력한 file data를 출력하는 함수
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

// Insertion Sort 를 이용하여 정렬
void sort() {
	float key_value;
	knapsack key;
	int j;

	for (int i = 1; i < N; i++) {
		key_value = kanpsack[i].pi_wi;
		key = kanpsack[i];

		// 정렬 완료 : i-1 이전
		// 정렬 미완료 : i-1 이후

		// key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
		for (j = i - 1; j >= 0 && kanpsack[j].pi_wi <= key_value; j--) {
			kanpsack[j + 1] = kanpsack[j];
		}
		kanpsack[j + 1] = key;
	}
}





// queue 초기화
void queue_init() {
	PQ.heap = (Element*)malloc(sizeof(Element)*N);
	PQ.size = 0;
}

// 큐가 비어있는지 확인
// 비어있으면 True, 비어있지 않으면 False 반환
int is_empty() {
	if (PQ.size == 0)
		return TRUE;
	else
		return FALSE;
}

// 삽입 (enqueue) 함수
void insert(Element node) {
	Element temp;
	int i = PQ.size;  // queue의 크기
	int parent = (i - 1) / 2; // 부모의 인덱스 
	PQ.heap[i] = node;
	PQ.size++; // queue의 크기 증가

	// 해당하는 부분을 찾아서 삽입한다.
	while ((PQ.heap[i].value > PQ.heap[parent].value) && (i > 0)) {
		temp = PQ.heap[i];
		PQ.heap[i] = PQ.heap[parent];
		PQ.heap[parent] = temp;

		i = parent;
		parent = (i - 1) / 2;
	}
}

// 삭제 : dequeue 함수
Element delete_() {
	Element result = PQ.heap[0]; //제일 위에있는 루트노드 반환할 노드
	Element tmp;
	int i = 0, big = 0, cleft = 1, cright = 2;

	PQ.size--; // 삭제하였으므로 queue의 크기 감소
	PQ.heap[0] = PQ.heap[PQ.size];

	while ((cleft < PQ.size) && (cleft < PQ.size)) {
		// 더 작은 자식노드를 찾는 과정
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
		cleft = 2 * i + 1; //왼쪽 자식노드
		cright = 2 * i + 2; //오른쪽 자식노드
	}

	if (cright == PQ.size) {
		tmp = PQ.heap[i];
		PQ.heap[i] = PQ.heap[cleft];
		PQ.heap[cleft] = tmp;

		i = cleft;
		cleft = 2 * i + 1; //왼쪽 자식노드
		cright = 2 * i + 2; //오른쪽 자식노드

	}

	return result;
}


//Best First Search With Branch And Bound
Element best_BB(void) {
	int best; // best값
	Element u, v, rnode;
	int i;

	v = bound(0, 0); //(0,0)을 루트로 하여 먼저 넣는다.
	insert(v);
	best = v.value;

	// Back Tracking 방법을 사용하여 해를 찾는 과정
	while (!is_empty())
	{
		v = delete_();
		for (i = 0; i < 2; i++) {
			u = bound(v.a + 1, 2 * v.b + i);
			if (u.current_sum <= M) {
				// 넘치지 않는 경우 best값을 업데이트 시켜준다.
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

//Bound의 값을 계산하는 함수
Element bound(int a, int b) {
	int enable_capacity;
	Element node;
	float c;

	node.a = a;
	node.b = b;
	node.X = (int*)malloc(sizeof(int)*a);

	// X에 해당값이 들어가면 1을 넣고 그렇지 않으면 0 을 넣는다.
	for (int i = 0; i < node.a; i++) {
		node.X[i] = (b >> (node.a - i - 1) & 1);
	}

	node.value = 0;
	node.current_sum = 0;

	for (int i = 0; i < node.a; i++) {
		// 들어가 있는 경우
		if (node.X[i] == 1) {
			node.value += kanpsack[i].pi;
			node.current_sum += kanpsack[i].wi;
		}
	}

	int i = node.a;
	node.bound = node.value;
	enable_capacity = M - node.current_sum;

	// bound 계산
	while ((enable_capacity > 0) && (i < N)) {
		if (enable_capacity >= kanpsack[i].wi) {
			enable_capacity -= kanpsack[i].wi;
			node.bound += kanpsack[i].pi;
			i++;
		}
		else {
			c = (float)enable_capacity / (float)kanpsack[i].wi;
			enable_capacity = 0; // 딱 맞게 채워넣는다.
			node.bound += (float)kanpsack[i].pi * c;
		}
	}
	return node;
}


// 정답을 출력하는 함수
void print_answer(Element node) {
	for (int i = 0; i < N; i++) {
		if (node.X[i] == 1) {
			kanpsack[kanpsack[i].index].X = 1;
		}
		else {
			kanpsack[kanpsack[i].index].X = 0;
		}
	}
	// Maximum profit 출력
	printf("\n");
	printf("The maximum profit is $%d", node.value);

	//해벡터 출력
	printf("\nThe solution vector X = (");
	for (int i = 0; i < N - 1; i++) {
		printf("%d, ", kanpsack[i].X);
	}
	printf("%d)\n", kanpsack[N - 1].X);
}