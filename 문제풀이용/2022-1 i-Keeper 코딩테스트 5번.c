#include<stdio.h>
#include<string.h>
int main() {
	char arr[141] = { 0 }; //입력받을 문자열
	char arr_sort[97] = { 0 }; //정렬된 문자열
	int count[97] = { 0 }; //문자 카운트
	gets(arr); //공백 구분없이 문자열 입력

	int lenth_arr = strlen(arr); //문자열 길이

	for (int i = 0; i < lenth_arr; i++) {
		arr_sort[arr[i] - 32] = arr[i]; //[입력받은문자-32]번에 문자삽입(글자 종류중 공백이 32로 가장 작음 따라서 -32로 0번부터 순서대로 삽입)
		count[arr[i] - 32]++; //[입력받은 문자-32]번 칸에 카운트
	}
	for (int i = 0; i <= 96; i++) {
		if (arr_sort[i] != '\0') { //값이 있을때만 출력
			printf("%c : %d\n", arr_sort[i], count[i]);
		}
	}
	for (int i = 0; i < lenth_arr - 1; i++) { //텍스트 아스키 코드값으로 정렬
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