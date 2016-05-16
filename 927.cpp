#include <cstdio>
#include <cmath>

using namespace std;

int main (void) {
	int times, len, index, i, d, k;
	long poly[21], ans;

	scanf("%d", &times);

	while (times-- > 0) {
		scanf("%d", &len);
		for (i = 0; i <= len; ++i) scanf("%ld", poly + i);
		scanf("%d %d", &d, &k);

		index = (int)sqrt((double)k * 2 / d);
		if (index * (index + 1) * d / 2 < k) ++index;
		ans = 0;
		for (i = 0; i <= len; ++i) ans += poly[i] * pow((long)index, i);
		printf("%ld\n", ans);
	}

	return 0;
}
