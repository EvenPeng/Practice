#include <cstdio>
#include <cstring>

using namespace std;

#define BASE 1000000000000000 

int digit[367][10];

int main (void) {
	int len, i, j, n;
	long list[60], tmpL;

	memset(digit[0], 0, sizeof(int) * 10);
	digit[0][0] = 1;
	memset(digit[1], 0, sizeof(int) * 10);
	digit[1][1] = 1;
	memset(digit[2], 0, sizeof(int) * 10);
	digit[2][2] = 1;

	memset(list, 0, sizeof(long) * 60);
	list[0] = 2;
	len = 1;

	for (i = 3; i < 367; ++i) {
		memset(digit[i], 0, sizeof(int) * 10);
		for (j = 0; j < len; ++j) list[j] *= i;
		for (j = 0; j < len; ++j) {
			list[j + 1] += list[j] / BASE;
			list[j] %= BASE;
		}
		while (list[len] > 0) ++len;
		for (j = 0; j < len - 1; ++j) {
			tmpL = list[j];
			for (n = 0; n < 15; ++n) {
				digit[i][tmpL % 10] ++;
				tmpL /= 10;
			}
		}
		tmpL = list[len - 1];
		while (tmpL > 0) {
			digit[i][tmpL % 10] ++;
			tmpL /= 10;
		}
	}

	while (scanf("%d", &n) != EOF) {
		if (n < 1) break;
		printf("%d! --\n", n);
		for (i = 0; i < 5; ++i) printf("   (%d)%5d", i, digit[n][i]);
		printf("\n");
		for (i = 5; i < 10; ++i) printf("   (%d)%5d", i, digit[n][i]);
		printf("\n");
	}

	return 0;
}
