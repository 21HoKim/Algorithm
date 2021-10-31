#include<stdio.h>
#include<string.h>
int math(char s[],int cut,int n){ //문자열을 압축하는 함수 
	       //배열,자를기준,문자열 길이
	//cut : 자르는 기준  //n : 문자열 길이
	int zip = 0; //압축된 문자열 길이
	int count = 0;
	for (int i = 0; i < n; ) {
		if (n - (i + cut) <= 0 && count==0) {
			zip++;
			i++;
			//printf("count \n");
		}
		else if (s[i] != s[i + cut] && count==0) {
			zip += cut;
			i += cut;
		}
		else if (s[i] != s[i + cut] && count > 0 && count/cut<9) {
			zip += cut + 1; 
			if (i + cut > n && i+cut ==n) {
				i += cut-count;
				//printf("C!!\n");
			}
			else {
				i += cut;
			}
			if (count < cut) {
				i -= count;
				zip -= 1;
			}
			count = 0;
		}
		else if (s[i] != s[i + cut] && count > 0 && count/cut >=9 ) {
			zip += cut + 2;
			if (!(i + cut < n) && i + cut != n) {
				i += cut - count;
				//printf("C2!!\n");
			}
			else {
				i += cut;
			}
			if (count < cut) {
				i -= count;
				zip -= 2;
			}
			count = 0;
		}
		else {
			count++;
			i++;
		}
	}
	return zip; 
}
int main() {
	//입력값 :aabbaccc:7 ababcdcdababcdcd:9 abcabcdede:8 abcabcabcabcdededededede:14 xababcdcdababcdcd:17 xababcdcdababcdcdxababcdcdababcdcd:-1
	char s[100]; //입력받을 문자열 
	int n; //문자열의 길이
	int min = 999; //압축된 경우의 최소값
	int zip1 ; //압축된 문자열 길이
	scanf("%s", s);
	n = strlen(s);
	if (n > 30) { //입력길이 최대값을 넘었을때 -1 출력
		printf("-1");
	}
	else {
		for (int i = 1; i <= n; i++) { //자르는 기준을 바꾸면서 가장 많이 압축된 결과값을 찾는다
			zip1=math(s,i,n); //zip1변수에 자르는기준에따른 배열길이를 입력받는다
			//printf("기준=%d zip1=%d\n",i,zip1);
			if (zip1 < min) { //최소값을 찾는 조건문
				min = zip1;

			}
		}
		printf("%d\n",min);
	}
	return 0;
}