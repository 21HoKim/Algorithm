#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int quick(int* ptr, int start, int end) {
	if (start >= end) { //오버플로우 방지  
		//원소가 1개인 경우  
		return;
	}
	int pivot = start;
	int i = pivot + 1; //왼쪽 출발지점  
	int j = end; // 오른쪽 출발지점 
	int temp;
	int t = 0;
	while (i <= j) {
		//포인터가 엇갈릴때까지 반복  
		while (i <= end && ptr[i] <= ptr[pivot]) {
			i++;
		}
		while (j > start && ptr[j] >= ptr[pivot]) {
			j--;
		}
		if (i > j) {
			//엇갈림 
			temp = ptr[j];
			ptr[j] = ptr[pivot];
			ptr[pivot] = temp;
			//	printf("%s %s\n",name_U[j],name_U[pivot]);
		}
		else {
			//i번째와j번째를 스왑 
			temp = ptr[i];
			ptr[i] = ptr[j];
			ptr[j] = temp;
			//		printf("%s %s\n",name_U[i],name_U[j]);

		}
	} t++;
	//분할계산 (재귀) 
	quick(ptr, start, j - 1);
	quick(ptr, j + 1, end);
}
int main() {
	int a;
	scanf("%d", &a);
	int* ptr = malloc(sizeof(int) * a);
	for (int i = 0; i < a; i++) {
		scanf("%d", &ptr[i]);
	}
	quick(ptr, 0, a - 1);
	printf("%d %d", ptr[0], ptr[a - 1]);
	free(ptr);
	return 0;
}