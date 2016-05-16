#include <cstdio>
#include <algorithm>

using namespace std;

int main (void) {
	int times, len, coin[101], dp[25001], i, j, sum, avg;

	scanf("%d", &times);

	while (times-- > 0) {
		scanf("%d", &len);

		sum = 0;
		for (i = 0; i < len; ++i) {
			scanf("%d", coin + i);
			sum += coin[i];
		}
		avg = sum / 2;

		for (j = 0; j <= len * 250; ++j) dp[j] = 0;
		
		for (i = 0; i < len; ++i)
		for (j = avg; j >= coin[i]; --j) dp[j] = max(dp[j], dp[j - coin[i]] + coin[i]);

		printf("%d\n", sum - 2 * dp[avg]);
	}

	return 0;
}
