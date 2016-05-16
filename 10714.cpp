#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	int times, i, l, n, min, max, R, L;

	scanf("%d", &times);
	while (times--) {
		scanf("%d %d", &l, &n);
		scanf("%d", &R);
		L = l - R;
		max = L > R? L: R;
		min = L > R? R: L;
		for (i = 1; i < n; ++i) {
			scanf("%d", &R);
			L = l - R;
			if (R > L) {
				if (min < L) min = L;
				else if (max < R) max = R;
			} else {
				if (min < R) min = R;
				else if (max < L) max = L;
			}
		}
		printf("%d %d\n", min, max);
	}

	return 0;
}
