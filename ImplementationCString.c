#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int cus_strlen(char* str) {
	int cnt = 0;
	if (*str == '\0') { return 0; }
	while (*str != '\0') {
		str++;
		++cnt;
	}
	return cnt;
}

// strcmp - 문자열 비교,
// 앞의 문자가 크면 -1
// 뒤의 문자가 크면 1
// 같으면 0
int cus_strcmp(char* str1, char* str2) {
	char c1, c2;
	// 한쪽 문자열이 끝날 때까지 비교 수행
	while (*str1!='\0' || *str2!='\0') {
		c1 = *str1;
		c2 = *str2;
		if (c1 != c2) { return c1 > c2 ? 1 : -1; }

		if (!c1) break;

		str1++;
		str2++;
	}

	return 0;
}

// 문자열의 시작주소 반환
char* cus_strstr(char* str1, char* str2) {
	if (str2[0] == '\0') { return (char*)str1; }

	while (*str1 != '\0') {
		int i = 0;

		while (*(str1 + i) == *(str2 + i)) {
			i++;
			if (*(str2 + i) == '\0') {
				return (char*) str1;
			}
		}

		str1++;
	}
	return (char*)NULL;
}
char* cus_strcpy(char* dest, const char* src)
{
	char* tmp = dest;

	while (*src) {
		*tmp++ = *src++;
	}
	*tmp = '\0';

	return dest;
}

char* cus_strcat(char* str1, char* str2) {
	char* temp = str1;
	while (*str1 != '\0') {
		str1++;
	}
	while (*str2 != '\0') {
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';

	return temp;
}

int main() {
	char a[20][100] = { "", "block", "blockAmask", "blockDmask", "BlockAmask", "BlockDmask", 
		"Mask", "mask", "BlockAMask", "BlockDMask", "Block", "mask", "alockAmask", "BleckDmask", "BlockAmesk", "BlockDMesk",
	"a", "M", "ab", "Ms"};

	for (int i = 0; i < 20; i++) {
		printf("strlen test - %d : %s\n", i + 1, (cus_strlen(a[i]) == strlen(a[i])) ? "Success" : "Fail");
	}
	printf("-------\n");

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			printf("strcmp test - %d(%d) : %s\n", i, j, (cus_strcmp(a[i], a[j]) == strcmp(a[i], a[j])) ? "Success" : "Fail");
		}
		printf("\n");
	}
	printf("-------\n");

	for (int i = 0; i < 20; i++) {
		for (int j = i; j < 20; j++) {
			printf("strstr test - %d(%d) : %s\n", i, j, (cus_strstr(a[i], a[j]) == strstr(a[i], a[j])) ? "Success" : "Fail");
		}
		printf("\n");
	}

	printf("-------\n");

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			char c[100];
			char t[100];

			strcpy(c, a[i]); strcpy(t, a[i]);

			if (strcmp(cus_strcat(c, a[j]), strcat(t, a[j])) == 0) {
				printf("strcat test - %d(%d) : Success\n", i, j);
			}

			else {
				printf("strcat test - %d(%d) : Fail\n", i, j);
			}

		}
		printf("\n");
	}
	
	return 0;
}