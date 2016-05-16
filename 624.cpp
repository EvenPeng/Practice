#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	bool check[20];
	int len, list[20], dp[100000], best[100000];
	int i, j, n;

	while (scanf("%d", &n) != EOF) {
		scanf("%d", &len);
		for (i = 0; i < len; ++i) scanf("%d", list + i);
		memset(check, false, sizeof(bool) * len);
		memset(dp, 0, sizeof(int) * (n + 1));
		memset(best, -1, sizeof(int) * (n + 1));

		for (i = 0; i < len; ++i) {
			for (j = n; j >= list[i]; --j)
			if (dp[j] < dp[j - list[i]] + list[i]) {
				dp[j] = dp[j - list[i]] + list[i];
				best[j] = i;
			}
		}

		i = dp[n];
		while (best[i] > -1) {
			check[best[i]] = true;
			i -= list[best[i]];
		}

		for (i = 0; i < len; ++i) if (check[i]) printf("%d ", list[i]);
		printf("sum:%d\n", dp[n]);
	}

	return 0;
}
