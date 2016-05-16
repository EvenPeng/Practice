#include <cstdio>
#include <cstring>

using namespace std;

bool table[101][101];
int num[101], low[101], cnt[101], n, sum, acc;

void dfs (int index) {
	bool flag;
	int i;

	flag = false;
	num[index] = acc;
	low[index] = acc;

	acc ++;
	for (i = 1; i <= n; ++i)
	if (table[index][i]) {
		table[i][index] = false;
		if (!num[i]) {
			cnt[index] ++;
			dfs(i);
			if (low[i] < low[index]) low[index] = low[i];
			if (low[i] >= num[index]) flag = true;
		}
		else if (num[i] < low[index]) low[index] = num[i];
	}

	if (cnt[index] > 0 && flag) sum ++;
}

int main (void) {
	char c;
	int i, j, s, t;

	while (true) {
		scanf("%d", &n);
		if (n == 0) break;

		for (i = 1; i <= n; ++i) memset(&table[i][1], false, sizeof(bool) * n);

		while (true) {
			scanf("%d", &s);
			if (s == 0) break;
			while (true) {
				scanf("%d%c", &t, &c);
				table[s][t] = true;
				table[t][s] = true;
				if (c != ' ') break;
			}
		}

		for (i = 1; i <= n; ++i) {
			cnt[i] = 0;
			num[i] = 0;
		}
		acc = 1;
		sum = 0;
		dfs(1);

		if (cnt[1] == 1) sum --;
		printf("%d\n", sum);
	}

	return 0;
}
