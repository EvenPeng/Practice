#include <cstdio>
#include <cstring>

using namespace std;

bool isPrime[1000000];
int lenB, primeNum[1000000];

int main (void) {
	int n, i, j, beg, end, digitSum, tmpI, step;

	memset(isPrime, true, sizeof(bool) * 1000000);
	isPrime[1] = false;
	primeNum[0] = 0;
	primeNum[1] = 0;
	primeNum[2] = 1;
	for (i = 4; i < 1000000; i += 2) isPrime[i] = false;
	for (i = 3; i < 1000000; i += 2) {
		primeNum[i] = primeNum[i - 1];
		if (isPrime[i]) {
			step = i * 2;
			for (j = step + i; j < 1000000; j += step) isPrime[j] = false;
			tmpI = i;
			digitSum = 0;
			while (tmpI) {
				digitSum += tmpI % 10;
				tmpI /= 10;
			}
			if (isPrime[digitSum]) primeNum[i] ++;
		}
		primeNum[i + 1] = primeNum[i];
	}

	scanf("%d", &n);
	lenB = 0;
	for (i = 0; i < n; ++i) {
		scanf("%d %d", &beg, &end);
		printf("%d\n", primeNum[end] - primeNum[beg - 1]);
	}

	return 0;
}
