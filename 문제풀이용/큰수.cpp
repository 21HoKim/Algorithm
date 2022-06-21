#include<stdio.h>
#include<stdlib.h>
int compare(const void* a, const void* b) {
	int num1 = *(int*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	int num2 = *(int*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (num1 < num2)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ

	if (num1 > num2)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	return 0;
}
int main() {
	int sum = 0;
	int N, M, K; //N:�迭�� ũ��, M:���ڵ� ���Ҽ� �ִ� Ƚ�� K:�ε����� ���Ҽ� �ִ� Ƚ��
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