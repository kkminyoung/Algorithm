// ���� �˻� Ʈ�� ����
// (�ܼ� ����)

#include <stdio.h>

int tree[10002];


// print postorder traversal
void print_post(int left, int right) {
	// left index�� right index���� Ŀ���� �Ϸ�
	if (left > right)
		return; 

	// start : left, end : right
	int root = tree[left];
	int last = right;

	// ũ�� ������ last �ε��� ã�� ����
	while (tree[last] > root)
		last--;

	// last�� �������� left�� right�� ������
	print_post(left + 1, last);
	print_post(last + 1, right);

	// root �� ���
	printf("%d\n", root);
}

int main(void) {
	int temp;
	int N = 0;

	// ���� ��ȸ�� ��� �Է¹ޱ�
	while (scanf("%d", &temp) != -1)
		tree[N++] = temp;

	// ���� ��ȸ ���
	print_post(0, N - 1);

	return 0;
}