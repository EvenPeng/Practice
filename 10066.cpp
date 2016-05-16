#include <cstdio>

using namespace std;

int main (void) {
	int index, i, j, A[101], B[101], lenA, lenB, dp[101][101];

	index = 0;

	while (true) {
		scanf("%d %d", &lenA, &lenB);
		if (lenA == 0 && lenB == 0) break;

		for (i = 0; i < lenA; ++i) scanf("%d", A + i);
		for (i = 0; i < lenB; ++i) scanf("%d", B + i);

		dp[0][0] = A[0] == B[0]? 1: 0;
		for (i = 1; i < lenB; ++i) dp[0][i] = dp[0][i - 1] > 0 || A[0] == B[i]? 1: 0;
		for (i = 1; i < lenA; ++i) dp[i][0] = dp[i - 1][0] > 0 || A[i] == B[0]? 1: 0;

		for (i = 1; i < lenA; ++i)
		for (j = 1; j < lenB; ++j) {
			dp[i][j] = dp[i - 1][j] > dp[i][j - 1]? dp[i - 1][j]: dp[i][j - 1];
			if (dp[i][j] == dp[i - 1][j - 1] && A[i] == B[j]) dp[i][j] ++;
		}

		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", ++index, dp[lenA - 1][lenB - 1]);
	}

	return 0;
}
