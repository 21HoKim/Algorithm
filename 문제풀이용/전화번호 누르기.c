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
int dis(int n, int r, int l) { //눌러야할 숫자n 현재 r과 l의 위치
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
	//좌표 다구함 이제 눌러야할 숫자와 자신의 거리
	int disR = abs(nx - rx) + abs(ny - ry);
	int disL = abs(nx - lx) + abs(ny - ly);
	//printf("\ndisL : %d disR : %d\n", disL, disR);
	if (disR > disL) { //R이 더 멀때
		return 1;
	}
	else if (disR < disL) { //L이 더 멀때
		return -1;
	}
	else { //두 손가락 위치가 같을때
		return 0;
	}

}
int main() {
	int N[10000],cnt=0;
	char H[10];
	char str[10000] = { 0 }, * s;
	bool R; //오른손 잡이 인지, 아니면 왼속잡이
	gets(str);
	scanf("%s", H);
	int right = 12;
	int left = 10;
	for (s = strtok(str, " "); s; s = strtok(NULL, " "), cnt++) { //cnt는 입력한 정수 배열의 길이가 됨
		if (sscanf(s, "%d", &N[cnt]) < 1) // s의 문자열을 N에 숫자로 바꿔서 넣음 아무것도 못읽으면 0, 읽기전에 입력실패면 EOF
			break;
	} //N에 문자 차례대로 기록됨
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
		else { //2 5 8 0 일 경우
			if (dis(n, right, left) == 1) { //R이 더 멀때
				printf("L");
				left = n;
			}
			else if (dis(n, right, left) == -1) {//L이 더 멀때
				printf("R");
				right = n;
			}
			else {//거리가 같을때
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