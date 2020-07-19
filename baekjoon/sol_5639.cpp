// 이진 검색 트리 문제
// (단순 버전)

#include <stdio.h>

int tree[10002];


// print postorder traversal
void print_post(int left, int right) {
	// left index가 right index보다 커지면 완료
	if (left > right)
		return; 

	// start : left, end : right
	int root = tree[left];
	int last = right;

	// 크기 순으로 last 인덱스 찾는 과정
	while (tree[last] > root)
		last--;

	// last를 기준으로 left와 right를 나눈다
	print_post(left + 1, last);
	print_post(last + 1, right);

	// root 값 출력
	printf("%d\n", root);
}

int main(void) {
	int temp;
	int N = 0;

	// 전위 순회한 결과 입력받기
	while (scanf("%d", &temp) != -1)
		tree[N++] = temp;

	// 후위 순회 출력
	print_post(0, N - 1);

	return 0;
}