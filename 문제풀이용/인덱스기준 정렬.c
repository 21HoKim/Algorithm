/*#include<stdio.h>
#include<string.h>
void sort(char arr[][101], int n, int size) {
	//n은 인덱스 기준숫자
	int N;					
	int a;
	char temp[101]; //교환할때 사용
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
			else if (arr[j][n] == arr[j + 1][n]) { //만약 인덱스가 같다면 사전순 정렬
				count = 0;
				int min_arrlen,max_arrlen;
				if(strlen(arr[j])<strlen(arr[j+1])){ //뒤에가 클때 
					min_arrlen = strlen(arr[j]);
					max_arrlen = strlen(arr[j + 1]);
					a = 0;
				}
				else { //앞에가 클때
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
				if (count == min_arrlen && a == 1) { //앞에놈이 더 클때
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
	char arr[50][101] = { 0 }; //세로 50 가로 101
	int size_arr;
	int count = 0;

	char arrcut[5000] = { 0 }; //자를때 사용
	scanf("%d%*c", &size_arr); //*는 버림을 의미 줄내림\n을 버려서 버퍼를 비워주어 gets()함수 사용이 정상적으로 되게 함

	gets(arrcut); //\n개행문자가 남아있어서 버퍼를 미리 비워주어야함
	int N = strlen(arrcut);
	arrcut[N] = '\0'; //gets()함수는 널문자를 넣지않음
	int n;
	scanf("%d", &n);
	//printf("n=%d\n", n);
	char* ptr = strtok(arrcut, " "); //https://blockdmask.tistory.com/382 , 공백에 널문자를 넣고 문자를 가리키는 포인터 반환
	int i=0;
	while (ptr != NULL)              //ptr이 NULL일때까지 (= strtok 함수가 NULL을 반환할때까지)
	{
		//printf("%s\n", ptr); //자른 문자 출력
		strcat(arr[i], ptr);
		ptr = strtok(NULL, " "); //자른 문자 다음부터 구분자 또 찾기
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
	//n은 인덱스 기준숫자
	int N;
	int a;
	char temp[101]; //교환할때 사용
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
			else if (arr[j][n] == arr[j + 1][n]) { //만약 인덱스가 같다면 사전순 정렬
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
	char arr[50][101] = { 0 }; //세로 50 가로 101
	int size_arr;
	int count = 0;

	char arrcut[5000] = { 0 }; //자를때 사용
	scanf("%d%*c", &size_arr); //*는 버림을 의미 줄내림\n을 버려서 버퍼를 비워주어 gets()함수 사용이 정상적으로 되게 함

	gets(arrcut); //\n개행문자가 남아있어서 버퍼를 미리 비워주어야함
	int N = strlen(arrcut);
	arrcut[N] = '\0'; //gets()함수는 널문자를 넣지않음
	int n;
	scanf("%d", &n);
	//printf("n=%d\n", n);
	char* ptr = strtok(arrcut, " "); //https://blockdmask.tistory.com/382 , 공백에 널문자를 넣고 문자를 가리키는 포인터 반환
	int i = 0;
	while (ptr != NULL)              //ptr이 NULL일때까지 (= strtok 함수가 NULL을 반환할때까지)
	{
		//printf("%s\n", ptr); //자른 문자 출력
		strcat(arr[i], ptr);
		ptr = strtok(NULL, " "); //자른 문자 다음부터 구분자 또 찾기
		i++;
	}
	sort(arr, n, size_arr);
	for (int i = 0; i < size_arr; i++) {
		printf("%s ", arr[i]);
	}
	return 0;
}