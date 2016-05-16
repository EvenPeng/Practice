#include <cstdio>
#include <cstring>

using namespace std;

bool exist;
int n, d, list[11], check, path[11];

static inline void show () {
	printf("(%d", path[0]);
	for (int i = 1; i < d; ++i) printf(",%d", path[i]);
	printf(",%d)\n", path[d]);
}

void route (int len, int x) {
	int i, j;

	if (len == d) {
		exist = true;
		show();
		return;
	}

	int mask = check & list[x];
	if (!mask) return;

	for (i = 2, j = 4; i <= n; ++i, j <<= 1) {
		if (mask & j) {
			path[len + 1] = i;
			check ^= j;
			route(len + 1, i);
			check ^= j;
		}
	}
}

int main (void) {	
	int i, j, k;

	path[0] = 1;
	while (scanf("%d %d", &n, &d) != EOF) {
		exist = false;
		for (i = 1; i <= n; ++i) {
			list[i] = 0;
			for (j = 1; j <= n; ++j) {
				scanf("%d", &k);
				if (k) list[i] += (1 << j);
			}
		}

		if (d < n) {
			check = (1 << (n + 1)) - 3;
			route(0, 1);
		}
		
		if (!exist) printf("no walk of length %d\n", d);
		if (scanf("%d", &n) != EOF) printf("\n");
	}

	return 0;
}
