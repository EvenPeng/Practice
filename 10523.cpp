#include <cstdio>
#include <cstring>

#define BASE 1000000000

using namespace std;

struct bignum {
	int l;
	long d[30];
} sum, base;

int main (void) {
	int n, a, i, j;

	while (scanf("%d %d", &n, &a) != EOF) {
		memset(sum.d, 0, sizeof(sum.d));
		sum.l = 1;
		memset(base.d, 0, sizeof(base.d));
		base.l = 1;
		base.d[0] = a;

		for (i = 1; i <= n; ++i) {
			for (j = 0; j < base.l; ++j) {
				sum.d[j] += base.d[j] * i;
				base.d[j] *= a;
			}
			for (j = 0; j < base.l; ++j) {
				base.d[j + 1] += base.d[j] / BASE;
				base.d[j] %= BASE;
			}
			if (base.d[j] > 0) ++base.l;
			for (j = 0; j < sum.l; ++j) {
				sum.d[j + 1] += sum.d[j] / BASE;
				sum.d[j] %= BASE;
			}
			if (sum.d[j] > 0) ++sum.l;
		}

		i = sum.l - 1;
		printf("%ld", sum.d[i]);
		while (--i > -1) printf("%09ld", sum.d[i]);
		printf("\n");
	}

	return 0;
}
