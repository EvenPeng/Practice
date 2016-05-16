#include <cstdio>

using namespace std;

long cnt[6001];

int main (void) {
	int i, j, n;

	for (i = 0; i < 6001; ++i) cnt[i] = i + 1;
	for (i = 2; i < 6001; ++i) cnt[i] += cnt[i - 2];
	for (i = 5; i < 6001; ++i) cnt[i] += cnt[i - 5];
	for (i = 10; i < 6001; ++i) cnt[i] += cnt[i - 10];

	while (scanf("%d", &n) != EOF)
		if (n > 4) printf("There are %ld ways to produce %d cents change.\n", cnt[n / 5], n);
		else printf("There is only 1 way to produce %d cents change.\n", n);

	return 0;
}
