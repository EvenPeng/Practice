#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main (void) {
	char num[300];
	int i, j, lenA, lenB;
	long A[40], B[40], C[80];

	while (scanf("%s", num) != EOF) {
		for (i = 0; i < 40; ++i) {
			A[i] = 0;
			B[i] = 0;
		}
		lenA = strlen(num);
		for (j = 1; j <= lenA; ++j)
			A[(lenA - j)/ 8] += (long)(num[j - 1] - '0') * pow(10,(lenA - j) % 8);
		lenA = lenA / 8;

		scanf("%s", num);
		lenB = strlen(num);
		for (j = 1; j <= lenB; ++j)
			B[(lenB - j)/ 8] += (long)(num[j - 1] - '0') * pow(10,(lenB - j) % 8);
		lenB = lenB / 8;

		for (i = 0; i < 80; ++i) C[i] = 0;
		for (i = 0; i <= lenA; ++i)
		for (j = 0; j <= lenB; ++j) {
			C[i + j] += A[i] * B[j];
			if (C[i + j] >= 100000000) {
				C[i + j + 1] += C[i + j] / 100000000;
				C[i + j] %= 100000000;
			}
		}
		i = 79;
		while (C[i] < 1 && i > 0) i --;
		printf("%ld", C[i]);
		while (i > 0) printf("%08ld", C[--i]);
		printf("\n");
	}

	return 0;
}
