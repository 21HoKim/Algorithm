/*#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int compare(void* first, void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}
int Mean(int sum,int N) {
	float A = (float)sum / N;
	int mean = A > 0 ? A + 0.5 : A - 0.5; //반올림
	return mean;
}
int Median(int *arr,int N) { //중앙값
	return arr[N / 2];
}
int Mode(int list[],int N) {
	int modeCount[8001] = { 0 };
	int i;
	int idx=0;
	int max=0;
	for ( i = 0; i < N; i++) {
		idx = list[i] + 4000;
		modeCount[idx] += 1; //최빈값 카운팅
		if (modeCount[idx] > max) { //최대 카운팅 수
			max = modeCount[idx];
		}
	}
	//printf("idx : %d\n", idx);
	int cnt = 0;
	for ( i = 0, idx = 0; i < 8001; i++) {
		if (modeCount[i] == 0)
			continue;
		if (modeCount[i] == max) {
			if (cnt == 0) {
				idx = i; 
				
				cnt += 1;
			}
			else if (cnt == 1) {
				idx = i;
				
				break;
			}
		}
	}
	return idx - 4000;	
}
int Range(int arr[], int N) { //범위
	return arr[N - 1] - arr[0];
}
int main() {
	int N;
	scanf("%d", &N);
	int sum = 0; //모든데이터의 합
	int* DataNum = malloc(sizeof(int) * N); //데이터받을 정수형 배열 동적할당
	for (int i = 0; i < N; i++) {
		scanf("%d", &DataNum[i]); //데이터 입력
		sum += DataNum[i];
	}
	qsort(DataNum, N, sizeof(DataNum[0]), compare);

	int mean=Mean(sum,N); //산술평균(반올림)
	int median=Median(DataNum,N); // 중앙값
	int mode=Mode(DataNum,N); // 최빈값
	int range=Range(DataNum,N); // 범위

	//printf("산술평균 : ");
	printf("%d\n",mean);
	//printf("중앙값 : ");
	printf("%d\n",median);
	//printf("최빈값 : ");
	printf("%d\n",mode);
	//printf("범위 : ");
	printf("%d\n",range);
	free(DataNum); //DataNum 메모리 할당 해제
	return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int compare(void* first, void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}
int Mean(int sum, int N) {
	float A = (float)sum / N;
	int mean = A > 0 ? A + 0.5 : A - 0.5; //반올림
	return mean;
}
int Median(int* arr, int N) { //중앙값
	return arr[N / 2];
}
int Mode(int* arr, int N) {
	int count = 0;
	int maxCount = -99;
	int maxCountInt = 0; //최빈값
	int countA = 0;
	bool A = false; //만약 최빈값이 여러개 있다면 true
	for (int i = 0; i < N; i++) {
		count = 0;
		for (int j = i; arr[i] == arr[j]; j++) {//달라질때까지 덧셈
			count++;
		}
		if (maxCount <= count) {
			if (maxCount == count) {
				A = true;
				countA = count;
				//break;
			}

			maxCount = count;
			maxCountInt = arr[i];
			//printf("최빈값 : %d\n", maxCountInt);
			//printf("maxCount : %d\n", maxCount);
		}
		i += count - 1;
	}
	if (A && countA == maxCount) {
		int count = 0;
		int count_B = 0;
		for (int i = 0; i < N; i++) {
			count = 0;
			for (int j = i; arr[j] == arr[i]; j++) {
				count++;
			}
			if (count == maxCount) {
				count_B++; //최빈값이 몇번 나왔나
			}
			if (count_B == 2) { //최빈값이 2번째로 나왔을때 2번째로 작은값
				return arr[i];
			}

			i += count - 1;

		}
	}
	else {
		return maxCountInt;
	}
}
int Range(int arr[], int N) { //범위
	return arr[N - 1] - arr[0];
}
int main() {
	int N;
	scanf("%d", &N);
	int sum = 0; //모든데이터의 합
	int* DataNum = malloc(sizeof(int) * N); //데이터받을 정수형 배열 동적할당
	for (int i = 0; i < N; i++) {
		scanf("%d", &DataNum[i]); //데이터 입력
		sum += DataNum[i];

	}
	qsort(DataNum, N, sizeof(DataNum[0]), compare);
	//for (int i = 0; i < N; i++) { printf("%d ", DataNum[i]); } printf("\n");
	int mean = Mean(sum, N); //산술평균(반올림)
	int median = Median(DataNum, N); // 중앙값
	int mode = Mode(DataNum, N); // 최빈값
	int range = Range(DataNum, N); // 범위
	//printf("%d\n%d\n%d\n%d\n", mean, median, mode, range);
	//printf("산술평균 : ");
	printf("%d\n", mean);
	//printf("중앙값 : ");
	printf("%d\n", median);
	//printf("최빈값 : ");
	printf("%d\n", mode);
	//printf("범위 : ");
	printf("%d\n", range);

	free(DataNum); //DataNum 메모리 할당 해제
	return 0;
}