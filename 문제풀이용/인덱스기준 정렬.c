#include<stdio.h>
#include<string.h>
void sort(char arr[][101], int n, int size) {
	//n�� �ε��� ���ؼ���
	int N;
	int a;
	char temp[101]; //��ȯ�Ҷ� ���
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j][n] > arr[j + 1][n]) { //n�� �������� ����
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
	//�� ���ڿ� ���̴� �ٸ�������
	char arrcut[5000] = { 0 }; //�ڸ��� ���
	scanf("%d%*c", &size_arr); //*�� ������ �ǹ� �ٳ���\n�� ������ ���۸� ����־� gets()�Լ� ����� ���������� �ǰ� ��

	gets(arrcut); //\n���๮�ڰ� �����־ ���۸� �̸� ����־����
	int N = strlen(arrcut);
	int n;
	scanf("%d", &n);
	char* ptr = strtok(arrcut, " "); //https://blockdmask.tistory.com/382 , ���鿡 �ι��ڸ� �ְ� ���ڸ� ����Ű�� ������ ��ȯ
	int i = 0;
	while (ptr != NULL)              //ptr�� NULL�϶����� (= strtok �Լ��� NULL�� ��ȯ�Ҷ�����)
	{
		//printf("%s\n", ptr); //�ڸ� ���� ���
		strcat(arr[i], ptr);
		ptr = strtok(NULL, " "); //�ڸ� ���� �������� ������ �� ã��
		i++;
	}
	sort(arr, n-1, size_arr);
	for (int i = 0; i <size_arr ; i++) {
		printf("%s ", arr[i]);
		
	}
	return 0;
}