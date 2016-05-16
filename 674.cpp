#include <cstdio>

using namespace std;

int main (void) {
	int n, cnt[7490];

	for (n = 0; n < 7490; ++n) cnt[n] = 1;
	for (n = 5; n < 7490; ++n) cnt[n] += cnt[n - 5];
	for (n = 10; n < 7490; ++n) cnt[n] += cnt[n - 10];
	for (n = 25; n < 7490; ++n) cnt[n] += cnt[n - 25];
	for (n = 50; n < 7490; ++n) cnt[n] += cnt[n - 50];

	while (scanf("%d", &n) != EOF) printf("%d\n", cnt[n]);

	return 0;
}
