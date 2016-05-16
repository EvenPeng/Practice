#include <cstdio>

using namespace std;

struct node {
	int val, min, chose;
};

int main (void) {
	int i, j, n, m, ans, pre, tmpI;
	node table[12][102];

	while (scanf("%d %d", &n, &m) != EOF) {
		for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j) {
			scanf("%d", &table[i][j].val);
			table[i][j].min = 0;
			table[i][j].chose = 0;
		}
		
		for (j = m; j > 1; --j)
		for (i = 1; i <= n; ++i) {
			tmpI = table[i][j].min + table[i][j].val;
			pre = i - 1 < 1? n: i - 1;
			if (table[pre][j - 1].chose == 0 || table[pre][j - 1].min > tmpI) {
				table[pre][j - 1].chose = i;
				table[pre][j - 1].min = tmpI;
			}
			pre = i;
			if (table[pre][j - 1].chose == 0 || table[pre][j - 1].min > tmpI) {
				table[pre][j - 1].chose = i;
				table[pre][j - 1].min = tmpI;
			}
			pre = i + 1 > n? 1: i + 1;
			if (table[pre][j - 1].chose == 0 || table[pre][j - 1].min > tmpI) {
				table[pre][j - 1].chose = i;
				table[pre][j - 1].min = tmpI;
			}
		}

		ans = table[1][1].min + table[1][1].val;
		for (i = 2; i <= n; ++i)
		if (table[i][1].min + table[i][1].val < ans)
			ans = table[i][1].min + table[i][1].val;
	
		for (i = 1; i <= n; ++i)
		if (table[i][1].min + table[i][1].val == ans) break;
		j = 1;
		while (j++ < m) {
			printf("%d ", i);
			i = table[i][j - 1].chose;
		}
		printf("%d\n%d\n", i, ans);
	}

	return 0;
}
