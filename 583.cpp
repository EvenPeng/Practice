#include <cstdio>
#include <cmath>

using namespace std;

int main (void) {
	bool flag, check[65537];
	int n, i, j, bound, len, prime[10000];

	len = 0;
	for (i = 2; i < 65537; ++i) check[i] = true;
	for (i = 2; i < 65537; ++i)
	if (check[i]) {
		for (j = 2 * i; j < 65537; j += i) check[j] = false;
		prime[len++] = i;
	}

	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		flag = false;
		if (n < 0) {
			printf("%d = -1", n);
			n *= -1;
			flag = true;
		} else printf("%d = ", n);

		bound = (int)sqrt((double) n);
		for (i = 0; n >  1 && prime[i] <= bound; ++i) {
			while (n > 1 && n % prime[i] == 0) {
				if (flag) printf(" x %d", prime[i]);
				else {
					printf("%d", prime[i]);
					flag = true;
				}
				n /= prime[i];
			}
		}

		if (n > 1) {
			if (flag) printf(" x %d", n);
			else printf("%d", n);
		}

		printf("\n");
	}

	return 0;
}
