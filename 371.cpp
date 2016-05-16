#include <cstdio>

using namespace std;

long seq (long x) {
	long len = 1;
	x = x % 2? 3 * x + 1: x / 2;

	while (x != 1)
	if (x % 2) {
		x += (x + 1) / 2;
		len += 2;
	} else {
		x /= 2;
		len ++;
	}

	return len;
}

int main (void) {
	long beg, end, i, maxI, max, tmpI;

	while (true) {
		scanf("%ld %ld", &beg, &end);
		if (beg == 0 && end == 0) break;

		if (beg > end) {
			tmpI = beg;
			beg = end;
			end = tmpI;
		}
	
		max = 0;
		for (i = beg; i <= end; ++i) {
			tmpI = seq(i);
			if (max < tmpI) {
				max = tmpI;
				maxI = i;
			}
		}

		printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n", beg, end, maxI, max);
	}

	return 0;
}
