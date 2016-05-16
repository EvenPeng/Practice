#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int gcd (int x, int y) {
	if (x > 0 && y > 0) while ((x %= y) && (y %= x));
	return x > y? x: y;
}

int main (void) {
	int times, i, j, n, m, list[101], max, tmpI, offset, len;
	char c[1000000], *num[100], tmpC;

	scanf("%d\n", &times);

	while (times-- > 0) {
		m = 0;
		gets(c);
		offset = 0;
		len = strlen(c);
		while (sscanf(c + offset, "%d%n", list + m, &tmpI) == 1) {
			m ++;
			offset += tmpI;
		}

		sort(list, list + m);

		max = 0;
		for (i = m - 1; i > 0 && list[i] >= max; --i)
		for (j = i - 1; j > -1 && list[j] >= max; --j) {
			tmpI = gcd(list[i], list[j]);
			if (tmpI > max) max = tmpI;
		}
		printf("%d\n", max);
	}

	return 0;
}
