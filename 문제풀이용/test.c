#include<stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int persent[101];
		char name[100];
		scanf("%c %d", &name, &persent);
		char temp = name[i];
		int max = persent[i];
		max < persent[i] ? max = persent[i] : max;

		if (max >= 80) {
			printf("%c��, �����б� ��ȸ���ĺ��� �缱�ǽ� ���� �����մϴ�!\n", max);
		}
		else("2�б⵵ �� ��Ź�����!\n");
	}
	return 0;
}
