#include<stdio.h>
int main() {
	char a[33];
	scanf("%s", a); //00000011 10000000 11111111 11111111 //00000011100000001111111111111111
	//printf("%s", a);
	int b[33];
	for (int i = 0; i < 32; i++) {
		b[i] = a[i] - 48; //���ڿ��� ���ڹ迭�� ��ȯ
		//printf("%d", b[i]);
	}
		for (int i = 0; i < 32; i++) {
			printf("%d", b[i]);
			if ((i - 7) % 8 == 0 && i != 0 && i != 31) {
				printf(".");
			}
		}
		printf("\n");
		int c[4][8]; //32�ڸ��� 8�ڸ��� ��� ������ �迭
		int d = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				c[i][j] = b[d];
				d++;
				//printf("%d", d);
				//printf("%d", c[i][j]);
			}
			//printf("\n");
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				//printf("%d", c[i][j]);
			}
		}
		int e[4][8]; //���� ��ȯ�� �ϱ����� 2������ �Ųٷ� ����
		for (int i = 0; i < 4; i++) {
			d = 0;
			for (int j = 7; j >= 0; j--) {
				e[i][d] = c[i][j];
				d++;
			}
		}
		/*for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				printf("%d", e[i][j]);
			}
			printf("\n");
		}*/
		int end[4];
		for (int i = 0; i < 4; i++) {
			int sum = 0;
			for (int j = 0; j < 8; j++) {
				if (e[i][j] == 1) {
					int m = 1;
					for (int k = 0; k < j; k++) {
						m = m * 2;
					}
					sum += m;
				}
			}
			end[i] = sum;
			/*printf("%d", sum);
			if (i != 3) {
				printf(".");
			}*/
		}
		for (int i = 0; i < 4; i++) {
			printf("%o", end[i]);
			if (i != 3) {
				printf(".");
			}
		}
		printf("\n");
		for (int i = 0; i < 4; i++) {
			printf("%d", end[i]);
			if (i != 3) {
				printf(".");
			}
		}
		printf("\n");
		for (int i = 0; i < 4; i++) {
			printf("%x", end[i]);
			if (i != 3) {
				printf(".");
			}
		}
		printf("\n");
		return 0;
}