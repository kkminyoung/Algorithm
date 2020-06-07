#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#include <time.h> 

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN -9999

int data[1000001];
int n; //file을 읽어올 때 저장할 data 개수
int file_len[10] = { 10, 100, 500,1000,5000,10000,50000,100000,500000,1000000 }; // file을 생성할 때 사용할 data 개수 

typedef struct Answer {
	int sum;
	int start;
	int end;
} Answer;


void file_write(FILE *file, int file_len);
void file_generator();
void file_read(int file_num);
Answer maxSum(int x[], int l, int u); // solution2(분할정복 방법)에서 사용되는 함수
Answer solution1_iterative(int data[], int n);
Answer solution2_DivideConquer(int data[], int n);
Answer solution3_dynamic(int data[], int n);


int main(void) {
	time_t start_time = 0;
	double time;

	//file2.txt ~ file10.txt를 만들어주는 함수실행
	//file_generator();

	for (int i = 1; i <= 10; i++) {
		int file_num = i;
		file_read(file_num);

		printf("solution1) : iterative\n");
		start_time = clock();
		Answer answer1 = solution1_iterative(data, n);
		printf("최대합 : %d 인덱스 : %d, %d\n", answer1.sum, answer1.start, answer1.end);
		time = (double)(clock() - start_time);
		printf("실행시간 : %fms\n\n", time);


		printf("solution2) : DivideConquer \n");
		start_time = clock();
		Answer answer2 = solution2_DivideConquer(data, n);
		time = (double)(clock() - start_time);
		printf("최대합 : %d 인덱스 : %d, %d\n", answer2.sum, answer2.start, answer2.end);
		printf("실행시간 : %fms\n\n", time);

		printf("solution3) : dynamic \n");
		start_time = clock();
		Answer answer3 = solution3_dynamic(data, n);
		time = (double)(clock() - start_time);
		printf("최대합 : %d 인덱스 : %d, %d\n", answer3.sum, answer3.start, answer3.end);
		printf("실행시간 : %fms\n\n", time);

		printf("----------------------------\n");

	}


	return 0;
}

void file_write(FILE *file, int file_len) {
	srand(time(NULL));

	int random = 0;
	int sign = 0;
	int data;

	fprintf(file, "%d\n", file_len);
	for (int j = 0; j < file_len; j++) {
		random = rand() % 100; // random data 생성
		sign = rand() % 2; // 양수, 음수를 결정하는 random number sign
		// 양수
		if (sign == 0) {
			data = random;
		}
		// 음수
		else if (sign == 1) {
			data = random * (-1);
		}
		fprintf(file, "%d ", data);
	}
}

//file2.txt ~ file10.txt 파일 생성
void file_generator() {
	FILE *file1, *file2, *file3, *file4, *file5, *file6, *file7, *file8, *file9, *file10 ;

	//fopen_s(&file1, "file1.txt", "w+"); file_write(file1, file_len[0]); -> file1은 음수로 구성된 data로 직접 만든다.
	fopen_s(&file2, "C:/Temp/file2.txt", "w+"); file_write(file2, file_len[1]);
	fopen_s(&file3, "C:/Temp/file3.txt", "w+"); file_write(file3, file_len[2]);
	fopen_s(&file4, "C:/Temp/file4.txt", "w+"); file_write(file4, file_len[3]);
	fopen_s(&file5, "C:/Temp/file5.txt", "w+"); file_write(file5, file_len[4]);
	fopen_s(&file6, "C:/Temp/file6.txt", "w+"); file_write(file6, file_len[5]);
	fopen_s(&file7, "C:/Temp/file7.txt", "w+"); file_write(file7, file_len[6]);
	fopen_s(&file8, "C:/Temp/file8.txt", "w+"); file_write(file8, file_len[7]);
	fopen_s(&file9, "C:/Temp/file9.txt", "w+"); file_write(file9, file_len[8]);
	fopen_s(&file10, "C:/Temp/file10.txt", "w+"); file_write(file10, file_len[9]);

}

void file_read(int file_num) {
	FILE *fp;
	int m;
	char fileName[100];

	sprintf(fileName, "C:/Temp/file%d.txt", file_num);
	fp = fopen(fileName, "r"); // txt 파일 읽어오기
	if (fp == NULL) { // 파일을 읽어오지 못하는 경우에 대한 예외처리
		printf("could not read file");
		return;
	}
	printf("< file%d.txt >\n", file_num);

	fscanf(fp, "%d", &n);

	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d", &data[i]);
	}

}

Answer solution1_iterative(int data[], int n) {
	Answer answer;

	int max = data[0];
	int r = 0;
	int s = 0;

	for (int i = 0; i < n; i++) {//시작 설정
		int v = 0; // sum 초기화
		for (int j = i; j < n; j++) {
			v = v + data[j];
			if (v > max) { //현재까지의 최대값 보다 크면 최댓값 업데이트
				max = v;
				r = i;
				s = j;
			}
		}
	}

	answer.sum = max;
	answer.start = r;
	answer.end = s;

	return answer;
}

Answer maxSum(int data[], int l, int u) {

	int m, i, sum;
	Answer left, right, crossing, crossing_left, crossing_right, temp;
	left.sum = MIN;
	right.sum = MIN;
	if (l == u) {
		if (data[l] >= MIN) {
			temp.sum = data[l];
			temp.start = l;
			temp.end = l;
			return temp;
		}
		else {
			temp.sum = MIN;
			temp.start = -1;
			temp.end = -1;
			return temp;
		}
	}
	else 
	{
		m = (l + u) / 2;

		//왼쪽 <- mid
		sum = 0;
		crossing_left.sum = MIN;
		for (i = m; i >= l; i--) {
			sum += data[i];
			// max( maxToLeft, sum)
			if (sum > left.sum) {
				crossing_left.sum = sum;
				crossing_left.start = i;
				crossing_left.end = m;
			}
		}

		// mid -> 오른쪽
		sum = 0;
		crossing_right.sum = MIN;
		for (i = m + 1; i <= u; i++) { 
			sum += data[i];
			// max( maxToRight, sum)
			if (sum > crossing_right.sum) { 
				crossing_right.sum = sum;
				crossing_right.start = m;
				crossing_right.end = i;
			}
		}

		crossing.sum = crossing_left.sum + crossing_right.sum;
		crossing.start = crossing_left.start;
		crossing.end = crossing_right.end;
	}

	left = maxSum(data, l, m);
	right = maxSum(data, m + 1, u);

	// MAX(crossing, left, right)
	// crossing이 제일 큰 경우
	if ((crossing.sum >= left.sum) && (crossing.sum >= right.sum)) {
		return crossing;
	}
	//left가 제일 큰 경우
	else if (left.sum >= right.sum) { 
		return left;
	}
	//right가 제일 큰 경우
	else { 
		return right;
	}
}

Answer solution2_DivideConquer(int data[], int n) {

	Answer answer = maxSum(data, 0, n - 1);
	return answer;
}



Answer solution3_dynamic(int data[], int n) {
	Answer Max, This;

	int max = data[0];
	int max_index = 0;

	Max.sum = 0;
	Max.start = 0;
	Max.end = 0;
	This.sum = 0;
	This.start = 0;
	This.end = 0;

	for (int i = 0; i < n; i++) {
		if (data[i] > max) {     
			max = data[i];
			max_index = i; 
		}

		// This.sum + data[i]가 양수인 경우 This.sum에 data[i]를 더해준다.
		if (This.sum + data[i] > 0) { 
			This.sum += data[i];
		}
		// 음수인 경우
		else { 
			This.sum = 0;
			This.start = i + 1;
		}

		// Max.sum = Max(This.sum, Max.sum)으로 업데이트
		if (This.sum >= Max.sum) { 
			Max.sum = This.sum;
			Max.start = This.start;
			Max.end = i; 
		}

	}


	// 최대값이 마이너스인 경우
	if (Max.sum <= 0) {
		Max.sum = max;
		Max.start = max_index;
		Max.end = max_index;
	}

	return Max;
}

