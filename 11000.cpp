#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	long cnt[50], i, j;

	cnt[0] = 0;
	cnt[1] = 1;
	cnt[2] = 2;
	for (i = 3; i < 50; ++i) cnt[i] = cnt[i -1] + cnt[i - 2] + 1;

	while (true) {
		scanf("%ld", &i);
		if (i < 0) break;
		printf("%ld %ld\n", cnt[i], cnt[i] + cnt[i - 1] + 1);
	}

	return 0;
}
