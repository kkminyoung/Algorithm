// �ǻ�� �ֱ⸦ �̿��� �Ǻ���ġ�� ����

#include<iostream>
#include <stdio.h>

long long a[1500050];
int I = 1000000; // �Ǻ���ġ���� ���� ��

void fibo() {
	a[0] = 0;
	a[1] = 1;
	//I�� ���� �Ǻ���ġ ������ �ݺ� �ֱ�� 1500000 �̴�.
	for (int i = 0; i < 1500000; i++) {
		a[i + 2] = (a[i + 1] + a[i]) % I;
	}
}

int main() {
	long long n;
	std::cin >> n;
	fibo();
	std::cout << a[n % 1500000] << "\n";

}
