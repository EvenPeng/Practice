#include <cstdio>

using namespace std;

int gcd (int i, int j) {
	while (i > 0 && j > 0) {
		if (i > j) i %= j;
		else j %= i;
	}

	if (i > j) return i;
	else return j;
}

int main (void) {
	int n, i, j, cnt;

	while (scanf("%d", &n) != EOF) {
		if (n < 1) break;

		cnt = 0;

		for (i = 1; i < n; ++i)
		for (j = i + 1; j <= n; ++j)
		cnt += gcd(i, j);

		printf("%d\n", cnt);
	}

	return 0;
}
