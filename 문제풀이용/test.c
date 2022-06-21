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
			printf("%c님, 다음학기 부회장후보로 당선되신 것을 축하합니다!\n", max);
		}
		else("2학기도 잘 부탁드려요!\n");
	}
	return 0;
}
