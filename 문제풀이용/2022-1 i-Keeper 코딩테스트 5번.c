#include<stdio.h>
#include<string.h>
int main() {
	char arr[141] = { 0 }; //�Է¹��� ���ڿ�
	char arr_sort[97] = { 0 }; //���ĵ� ���ڿ�
	int count[97] = { 0 }; //���� ī��Ʈ
	gets(arr); //���� ���о��� ���ڿ� �Է�

	int lenth_arr = strlen(arr); //���ڿ� ����

	for (int i = 0; i < lenth_arr; i++) {
		arr_sort[arr[i] - 32] = arr[i]; //[�Է¹�������-32]���� ���ڻ���(���� ������ ������ 32�� ���� ���� ���� -32�� 0������ ������� ����)
		count[arr[i] - 32]++; //[�Է¹��� ����-32]�� ĭ�� ī��Ʈ
	}
	for (int i = 0; i <= 96; i++) {
		if (arr_sort[i] != '\0') { //���� �������� ���
			printf("%c : %d\n", arr_sort[i], count[i]);
		}
	}
	for (int i = 0; i < lenth_arr - 1; i++) { //�ؽ�Ʈ �ƽ�Ű �ڵ尪���� ����
		char temp;
		for (int j = i + 1; j < lenth_arr; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("%s", arr);
	return 0;
}