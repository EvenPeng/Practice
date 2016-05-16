#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	bool first;
	int index, len, tmpI, list[100000], dp[100000], i, j;

	len = 0;
	index = 0;
	first = true;
	while (true) {
		scanf("%d", &tmpI);
		if (tmpI < 0) {
			if (len < 1) break;
			else {
				for (i = 0; i < len; ++i) dp[i] = 1;
				for (i = 0; i < len; ++i)
				for (j = i + 1; j < len; ++j)
				if (list[j] <= list[i]) dp[j] = dp[i] + 1 > dp[j]? dp[i] + 1: dp[j];
				for (i = 0; i < len - 1; ++i)
				dp[len - 1] = dp[len - 1] < dp[i]? dp[i]: dp[len - 1];

				if (!first) printf("\n");
				else first = false;
				printf("Test #%d:\n", ++index);
				printf("  maximum possible interceptions: %d\n", dp[len - 1]);
				len = 0;
			}
		} else list[len++] = tmpI;
	}

	return 0;
}
