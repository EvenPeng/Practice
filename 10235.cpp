#include <cstdio>
#include <cmath>

using namespace std;

int main (void) {
	bool check[1000000], pflag, eflag;
	int len, list[1000000], i, j, n, rn, beg, end, tmpInt;

	for (i = 2; i < 1000000; ++i) check[i] = true;
	for (i = 2; i < 1000000; ++i)
	if (check[i]) for (j = 2 * i; j < 1000000; j += i) check[j] = false;

	len = 0;
	for (i = 2; i < 1000000; ++i)
	if (check[i]) list[len++] = i;

	while (scanf("%d", &n) != EOF) {
		beg = 0;
		end = len;
		while (end - beg > 1) {
			i = (beg + end) / 2;
			if (list[i] > n) end = i;
			else if (list[i] < n) beg = i;
			else break;
		}
		pflag = list[i] == n;

		tmpInt = n;
		rn = 0;
		while (tmpInt > 0) {
			rn *= 10;
			rn += tmpInt % 10;
			tmpInt /= 10;
		}

		beg = 0;
		end = len;
		while (pflag && end - beg > 1) {
			i = (beg + end) / 2;
			if (list[i] > rn) end = i;
			else if (list[i] < rn) beg = i;
			else break;
		}
		eflag = n != rn && list[i] == rn;

		if (!pflag) printf("%d is not prime.\n", n);
		else if (!eflag) printf("%d is prime.\n", n);
		else printf("%d is emirp.\n", n);
	}

	return 0;
}
