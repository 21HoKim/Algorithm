/*#include<stdio.h>
#include<string.h>
void sort(char arr[][101], int n, int size) {
	//n�� �ε��� ���ؼ���
	int N;					
	int a;
	char temp[101]; //��ȯ�Ҷ� ���
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-i-1; j++) {	
			int count = 0;
			if (arr[j][n] > arr[j + 1][n]) {
				for (int k = 0; k < 100; k++) {
					temp[k] = arr[j + 1][k];
					arr[j + 1][k] = arr[j][k];
					arr[j][k] = temp[k];
				}
			}
			else if (arr[j][n] == arr[j + 1][n]) { //���� �ε����� ���ٸ� ������ ����
				count = 0;
				int min_arrlen,max_arrlen;
				if(strlen(arr[j])<strlen(arr[j+1])){ //�ڿ��� Ŭ�� 
					min_arrlen = strlen(arr[j]);
					max_arrlen = strlen(arr[j + 1]);
					a = 0;
				}
				else { //�տ��� Ŭ��
					min_arrlen = strlen(arr[j + 1]);
					max_arrlen = strlen(arr[j]);
					a = 1;
				}
				for (int L = 0; L< min_arrlen;L++) {
					
					if (arr[j][L] > arr[j + 1][L]) {
						for (int k = 0; k < 100; k++) {
							temp[k] = arr[j + 1][k];
							arr[j + 1][k] = arr[j][k];
							arr[j][k] = temp[k];
						}
						break;
					}
					else if(arr[j][L] == arr[j + 1][L]){
						count++;
					}
					if (arr[j][L] < arr[j+1][L]) {
						break;
					}
				}
				if (count == min_arrlen && a == 1) { //�տ����� �� Ŭ��
					for (int k = 0; k < 100; k++) {
						temp[k] = arr[j + 1][k];
						arr[j + 1][k] = arr[j][k];
						arr[j][k] = temp[k];
					}
				}
			}
		}
		printf("case %d : ", i);
		for (int i = 0; i < size; i++) {
			printf("%s ", arr[i]);
			//printf("%d\n",i);
		}
		printf("\n");
	}
}
int main() {
	char arr[50][101] = { 0 }; //���� 50 ���� 101
	int size_arr;
	int count = 0;

	char arrcut[5000] = { 0 }; //�ڸ��� ���
	scanf("%d%*c", &size_arr); //*�� ������ �ǹ� �ٳ���\n�� ������ ���۸� ����־� gets()�Լ� ����� ���������� �ǰ� ��

	gets(arrcut); //\n���๮�ڰ� �����־ ���۸� �̸� ����־����
	int N = strlen(arrcut);
	arrcut[N] = '\0'; //gets()�Լ��� �ι��ڸ� ��������
	int n;
	scanf("%d", &n);
	//printf("n=%d\n", n);
	char* ptr = strtok(arrcut, " "); //https://blockdmask.tistory.com/382 , ���鿡 �ι��ڸ� �ְ� ���ڸ� ����Ű�� ������ ��ȯ
	int i=0;
	while (ptr != NULL)              //ptr�� NULL�϶����� (= strtok �Լ��� NULL�� ��ȯ�Ҷ�����)
	{
		//printf("%s\n", ptr); //�ڸ� ���� ���
		strcat(arr[i], ptr);
		ptr = strtok(NULL, " "); //�ڸ� ���� �������� ������ �� ã��
		i++;
	}
	sort(arr, n,size_arr);
	for (int i = 0; i < size_arr; i++) {
		printf("%s ", arr[i]);

		//printf("%d\n",i);
	}
	return 0;
}*/
#include<stdio.h>
#include<string.h>
void sort(char arr[][101], int n, int size) {
	//n�� �ε��� ���ؼ���
	int N;
	int a;
	char temp[101]; //��ȯ�Ҷ� ���
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			int count = 0;
			if (arr[j][n] > arr[j + 1][n]) {
				for (int k = 0; k < 100; k++) {
					temp[k] = arr[j + 1][k];
					arr[j + 1][k] = arr[j][k];
					arr[j][k] = temp[k];
				}
			}
			else if (arr[j][n] == arr[j + 1][n]) { //���� �ε����� ���ٸ� ������ ����
				if (strcmp(arr[j], arr[j + 1]) > 0) {
					for (int k = 0; k < 100; k++) {
						temp[k] = arr[j + 1][k];
						arr[j + 1][k] = arr[j][k];
						arr[j][k] = temp[k];
					}
				}
			}
		}
	}
}
int main() {
	char arr[50][101] = { 0 }; //���� 50 ���� 101
	int size_arr;
	int count = 0;

	char arrcut[5000] = { 0 }; //�ڸ��� ���
	scanf("%d%*c", &size_arr); //*�� ������ �ǹ� �ٳ���\n�� ������ ���۸� ����־� gets()�Լ� ����� ���������� �ǰ� ��

	gets(arrcut); //\n���๮�ڰ� �����־ ���۸� �̸� ����־����
	int N = strlen(arrcut);
	arrcut[N] = '\0'; //gets()�Լ��� �ι��ڸ� ��������
	int n;
	scanf("%d", &n);
	//printf("n=%d\n", n);
	char* ptr = strtok(arrcut, " "); //https://blockdmask.tistory.com/382 , ���鿡 �ι��ڸ� �ְ� ���ڸ� ����Ű�� ������ ��ȯ
	int i = 0;
	while (ptr != NULL)              //ptr�� NULL�϶����� (= strtok �Լ��� NULL�� ��ȯ�Ҷ�����)
	{
		//printf("%s\n", ptr); //�ڸ� ���� ���
		strcat(arr[i], ptr);
		ptr = strtok(NULL, " "); //�ڸ� ���� �������� ������ �� ã��
		i++;
	}
	sort(arr, n, size_arr);
	for (int i = 0; i < size_arr; i++) {
		printf("%s ", arr[i]);
	}
	return 0;
}