#include <cstdio>

using namespace std;

long cnt[6001];

int main (void) {
	int i, j, n, c;

	for (i = 0; i < 6001; ++i) cnt[i] = 1;
	for (i = 2; i < 6001; ++i) cnt[i] += cnt[i - 2];
	for (i = 4; i < 6001; ++i) cnt[i] += cnt[i - 4];
	for (i = 10; i < 6001; ++i) cnt[i] += cnt[i - 10];
	for (i = 20; i < 6001; ++i) cnt[i] += cnt[i - 20];
	for (i = 40; i < 6001; ++i) cnt[i] += cnt[i - 40];
	for (i = 100; i < 6001; ++i) cnt[i] += cnt[i - 100];
	for (i = 200; i < 6001; ++i) cnt[i] += cnt[i - 200];
	for (i = 400; i < 6001; ++i) cnt[i] += cnt[i - 400];
	for (i = 1000; i < 6001; ++i) cnt[i] += cnt[i - 1000];
	for (i = 2000; i < 6001; ++i) cnt[i] += cnt[i - 2000];

	while (scanf("%d.%d", &n, &c) != EOF && (n > 0 || c > 0))
	printf("%3d.%02d%17ld\n", n, c, cnt[(n * 100 + c) / 5]);

	return 0;
}
