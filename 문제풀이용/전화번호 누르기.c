#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
int dirPad[4][3] = {
	{1,2,3},
	{4,5,6},
	{7,8,9},
	{10,0,12}
};
int dis(int n, int r, int l) { //�������� ����n ���� r�� l�� ��ġ
	int nx, ny;
	int rx, ry;
	int lx, ly;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (n == dirPad[i][j]) {
				nx = j;
				ny = i;
			}
			if (dirPad[i][j] == r) {
				rx = j;
				ry = i;
			}
			if (dirPad[i][j] == l) {
				lx = j;
				ly = i;
			}
		}
	}
	//��ǥ �ٱ��� ���� �������� ���ڿ� �ڽ��� �Ÿ�
	int disR = abs(nx - rx) + abs(ny - ry);
	int disL = abs(nx - lx) + abs(ny - ly);
	//printf("\ndisL : %d disR : %d\n", disL, disR);
	if (disR > disL) { //R�� �� �ֶ�
		return 1;
	}
	else if (disR < disL) { //L�� �� �ֶ�
		return -1;
	}
	else { //�� �հ��� ��ġ�� ������
		return 0;
	}

}
int main() {
	int N[10000],cnt=0;
	char H[10];
	char str[10000] = { 0 }, * s;
	bool R; //������ ���� ����, �ƴϸ� �޼�����
	gets(str);
	scanf("%s", H);
	int right = 12;
	int left = 10;
	for (s = strtok(str, " "); s; s = strtok(NULL, " "), cnt++) { //cnt�� �Է��� ���� �迭�� ���̰� ��
		if (sscanf(s, "%d", &N[cnt]) < 1) // s�� ���ڿ��� N�� ���ڷ� �ٲ㼭 ���� �ƹ��͵� �������� 0, �б����� �Է½��и� EOF
			break;
	} //N�� ���� ���ʴ�� ��ϵ�
	if (strcmp(H,"right")==0) {
		R = true;
	}
	else {
		R = false;
	}
	for (int i = 0; i < cnt; i++) {
		int n = N[i];
		

		if (n == 1 || n == 4 || n == 7) {
			left = n;
			printf("L");
		}
		else if (n == 3 || n == 6 || n == 9) {
			right = n;
			printf("R");
		}
		else { //2 5 8 0 �� ���
			if (dis(n, right, left) == 1) { //R�� �� �ֶ�
				printf("L");
				left = n;
			}
			else if (dis(n, right, left) == -1) {//L�� �� �ֶ�
				printf("R");
				right = n;
			}
			else {//�Ÿ��� ������
				if (R) {
					printf("R");
					right = n;
				}
				else {
					printf("L");
					left = n;
				}
			}
		}

	}

	
	return 0;
}