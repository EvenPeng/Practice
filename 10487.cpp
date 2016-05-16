#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main (void) {
	int n, m, i, j, l, r, index;
	int list[1001], goal, best, diff;

	index= 0 ;
	while (true) {
		scanf("%d", &n);
		if (!n) break;
		for (i = 0; i < n; ++i) scanf("%d", list + i);
		sort(list, list + n);
		scanf("%d", &m);
		printf("Case %d:\n", ++index);
		for (j = 0; j < m; ++j) {
			scanf("%d", &goal);
			best = list[0] + list[1];
			l = 0;
			r = n - 1;
			while (r > l) {
				diff = list[l] + list[r] - goal;
				if (abs(best - goal) > abs(diff)) best = list[l] + list[r];
				if (diff < 0) l ++;
				else if (diff > 0) r --;
				else break;
			}
			printf("Closest sum to %d is %d.\n", goal, best);
		}
	}

	return 0;
}
