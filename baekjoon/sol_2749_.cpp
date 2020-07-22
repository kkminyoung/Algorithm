// 피사노 주기를 이용한 피보나치수 문제

#include<iostream>
#include <stdio.h>

long long a[1500050];
int I = 1000000; // 피보나치수를 나눌 수

void fibo() {
	a[0] = 0;
	a[1] = 1;
	//I로 나눈 피보나치 수열의 반복 주기는 1500000 이다.
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
