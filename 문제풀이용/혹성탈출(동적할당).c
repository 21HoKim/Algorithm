#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	int a=0;//����ǿ� ���� ħ��ġ�� ��
	int count=0;
	scanf("%d", &a);
	int* lab = (int*)calloc(a+1, sizeof(int)); //������ ���� close : 0, open : 1, free : 2
	lab[1] = 1;
	for (int i = 1; i <= a; i++) {
		if (lab[i] == 1) {
			lab[i] = 2;
			count++;
			for (int j = i; j <= a; j+=i) {
					if (lab[j] == 0) {
						lab[j] = 1;
					}
					else if (lab[j] == 1) {
						lab[j] = 0;
					}
					else {
						continue;
					}
			}
		}
		else {
			continue;
		}
	}
	printf("%d", count);
	free(lab);
	return 0;
}