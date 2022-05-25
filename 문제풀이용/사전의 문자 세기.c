#include<stdio.h>
#include<string.h>
int main() {
	char arr[1000];
	int str[1000] = { 0 };
	scanf("%[^\n]s", arr);
	int n = strlen(arr);
	for (int i = 0; i < n; i++) {
		if (arr[i] == ' ' && arr[i + 1] == ' ') {
			break;
		}
		else if (arr[i] =='e' && arr[i + 1] =='n' && arr[i + 2] == 'd') {
			break;
		}
		else {
			if (arr[i] >= 97 && arr[i] <= 122) {
				str[arr[i] - 32]++;
			}
			else {
				str[arr[i]]++;
			}
		}
	}
	for (int i = 0; i < 1000; i++) {
		if (str[i] != 0 && i!=' ') {
			printf("%c : %d\n", i, str[i]);
		}
	}
	return 0;
}