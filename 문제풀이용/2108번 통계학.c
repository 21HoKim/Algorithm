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
	int mean = A > 0 ? A + 0.5 : A - 0.5; //�ݿø�
	return mean;
}
int Median(int *arr,int N) { //�߾Ӱ�
	return arr[N / 2];
}
int Mode(int list[],int N) {
	int modeCount[8001] = { 0 };
	int i;
	int idx=0;
	int max=0;
	for ( i = 0; i < N; i++) {
		idx = list[i] + 4000;
		modeCount[idx] += 1; //�ֺ� ī����
		if (modeCount[idx] > max) { //�ִ� ī���� ��
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
int Range(int arr[], int N) { //����
	return arr[N - 1] - arr[0];
}
int main() {
	int N;
	scanf("%d", &N);
	int sum = 0; //��絥������ ��
	int* DataNum = malloc(sizeof(int) * N); //�����͹��� ������ �迭 �����Ҵ�
	for (int i = 0; i < N; i++) {
		scanf("%d", &DataNum[i]); //������ �Է�
		sum += DataNum[i];
	}
	qsort(DataNum, N, sizeof(DataNum[0]), compare);

	int mean=Mean(sum,N); //������(�ݿø�)
	int median=Median(DataNum,N); // �߾Ӱ�
	int mode=Mode(DataNum,N); // �ֺ�
	int range=Range(DataNum,N); // ����

	//printf("������ : ");
	printf("%d\n",mean);
	//printf("�߾Ӱ� : ");
	printf("%d\n",median);
	//printf("�ֺ� : ");
	printf("%d\n",mode);
	//printf("���� : ");
	printf("%d\n",range);
	free(DataNum); //DataNum �޸� �Ҵ� ����
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
	int mean = A > 0 ? A + 0.5 : A - 0.5; //�ݿø�
	return mean;
}
int Median(int* arr, int N) { //�߾Ӱ�
	return arr[N / 2];
}
int Mode(int* arr, int N) {
	int count = 0;
	int maxCount = -99;
	int maxCountInt = 0; //�ֺ�
	int countA = 0;
	bool A = false; //���� �ֺ��� ������ �ִٸ� true
	for (int i = 0; i < N; i++) {
		count = 0;
		for (int j = i; arr[i] == arr[j]; j++) {//�޶��������� ����
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
			//printf("�ֺ� : %d\n", maxCountInt);
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
				count_B++; //�ֺ��� ��� ���Գ�
			}
			if (count_B == 2) { //�ֺ��� 2��°�� �������� 2��°�� ������
				return arr[i];
			}

			i += count - 1;

		}
	}
	else {
		return maxCountInt;
	}
}
int Range(int arr[], int N) { //����
	return arr[N - 1] - arr[0];
}
int main() {
	int N;
	scanf("%d", &N);
	int sum = 0; //��絥������ ��
	int* DataNum = malloc(sizeof(int) * N); //�����͹��� ������ �迭 �����Ҵ�
	for (int i = 0; i < N; i++) {
		scanf("%d", &DataNum[i]); //������ �Է�
		sum += DataNum[i];

	}
	qsort(DataNum, N, sizeof(DataNum[0]), compare);
	//for (int i = 0; i < N; i++) { printf("%d ", DataNum[i]); } printf("\n");
	int mean = Mean(sum, N); //������(�ݿø�)
	int median = Median(DataNum, N); // �߾Ӱ�
	int mode = Mode(DataNum, N); // �ֺ�
	int range = Range(DataNum, N); // ����
	//printf("%d\n%d\n%d\n%d\n", mean, median, mode, range);
	//printf("������ : ");
	printf("%d\n", mean);
	//printf("�߾Ӱ� : ");
	printf("%d\n", median);
	//printf("�ֺ� : ");
	printf("%d\n", mode);
	//printf("���� : ");
	printf("%d\n", range);

	free(DataNum); //DataNum �޸� �Ҵ� ����
	return 0;
}