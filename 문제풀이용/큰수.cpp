#include<stdio.h>
#include<stdlib.h>
int compare(const void* a, const void* b) {
	int num1 = *(int*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1 < num2)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (num1 > num2)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;
}
int main() {
	int sum = 0;
	int N, M, K; //N:배열의 크기, M:숫자들 더할수 있는 횟수 K:인덱스당 더할수 있는 횟수
	scanf("%d %d %d", &N, &M, &K);
	int *arr=(int *)malloc(sizeof(int)*N);
	if (K > M || N + K <= M) {
		printf("Condition error\n");
	}
	else {
		for (int i = 0; i < N; i++) {
			scanf("%d", arr + i);
		}
		qsort(arr, N, sizeof(int), compare);
		/*for (int i = 0; i < N; i++) {
			printf("%d ", *(arr + i));
		}*/
		int index = N-1;
		int count = 0;
		for (int i = 0; i < M; i++) {
			count++;
			sum += arr[index];
			if (count == K) {
				count = 0;
				index--;
			}

		}
		printf("%d\n", sum);
	}
	free(arr);
	return 0;
}