#include<stdio.h>
#include<string.h>
int math(char s[],int cut,int n){ //���ڿ��� �����ϴ� �Լ� 
	       //�迭,�ڸ�����,���ڿ� ����
	//cut : �ڸ��� ����  //n : ���ڿ� ����
	int zip = 0; //����� ���ڿ� ����
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
	//�Է°� :aabbaccc:7 ababcdcdababcdcd:9 abcabcdede:8 abcabcabcabcdededededede:14 xababcdcdababcdcd:17 xababcdcdababcdcdxababcdcdababcdcd:-1
	char s[100]; //�Է¹��� ���ڿ� 
	int n; //���ڿ��� ����
	int min = 999; //����� ����� �ּҰ�
	int zip1 ; //����� ���ڿ� ����
	scanf("%s", s);
	n = strlen(s);
	if (n > 30) { //�Է±��� �ִ밪�� �Ѿ����� -1 ���
		printf("-1");
	}
	else {
		for (int i = 1; i <= n; i++) { //�ڸ��� ������ �ٲٸ鼭 ���� ���� ����� ������� ã�´�
			zip1=math(s,i,n); //zip1������ �ڸ��±��ؿ����� �迭���̸� �Է¹޴´�
			//printf("����=%d zip1=%d\n",i,zip1);
			if (zip1 < min) { //�ּҰ��� ã�� ���ǹ�
				min = zip1;

			}
		}
		printf("%d\n",min);
	}
	return 0;
}