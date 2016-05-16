#include <cstdio>

using namespace std;

int main (void) {
	bool first, edge[101][101];
	int n, m, i, j, src, des, cnt[101], acc[101];

	while (scanf("%d %d", &n, &m) != EOF) {
		if (n == 0 && m == 0) break;

		for (i = 1; i <= n; ++i) {
			cnt[i] = 0;
			for (j = 1; j <= n; ++j) edge[i][j] = false;
		}
		
		for (i = 0; i < m; ++i) {
			scanf("%d %d", &src, &des);
			edge[src][des] = true;
			cnt[des]++;
		}

		first = true;

		while(true) {
			//for (i = 1; i <= n; ++i) printf("%d ", cnt[i]);
			//printf("\n");
			for (i = 1; i <= n; ++i) acc[i] = 0;
			for (i = 1; i <= n; ++i) if (cnt[i] == 0) break;
			if (i > n) break;
			for (; i <= n; ++i)
			if (cnt[i] == 0) {
				if (!first) printf(" ");
				printf("%d", i);
				first = false;
				cnt[i] = -1;
				for (j = 1; j <= n; ++j)
				if (edge[i][j]) acc[j]++;
			}
			for (i = 1; i <= n; ++i) cnt[i] -= acc[i];
		}

		printf("\n");
	}
	return 0;
}
