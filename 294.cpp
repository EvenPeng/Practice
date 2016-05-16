#include <cstdio>
#include <cmath>

using namespace std;

int find (int x) {
	int i, bound, cnt;

	if (x == 1) return 1;

	cnt = 2;

	bound = (int)(sqrt((double)x) + 0.5);

	for (i = 2; i <= bound; ++i)
		if (x % i == 0) cnt += 2;

	if (bound * bound == x)
		cnt --;

	return cnt;
}

int main (void) {
	int times, i, beg, end, max, maxIndex, tmpInt;

	scanf("%d", &times);

	while (times-- > 0) {
		scanf("%d %d", &beg, &end);
	
		maxIndex = beg;
		max = find(beg);
		for (i = beg + 1; i <= end; ++i) {
			tmpInt = find(i);
			if (tmpInt > max) {
				max = tmpInt;
				maxIndex = i;
			}
		}

		printf("Between %d and %d, %d has a maximum of %d divisors.\n", beg, end, maxIndex, max);
	}

	return 0;
}
