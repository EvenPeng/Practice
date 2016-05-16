#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	int cnt[1001][1001], i, j, lenA, lenB;
	char A[1002], B[1002];

	while (gets(A) != NULL) {
		gets(B);

		lenA = strlen(A);
		lenB = strlen(B);

		cnt[0][0] = A[0] == B[0]? 1: 0;
		for (i = 1; i < lenA; ++i)
			cnt[i][0] = cnt[i - 1][0] || A[i] == B[0]? 1: 0;
		for (j = 1; j < lenB; ++j)
			cnt[0][j] = cnt[0][j - 1] || A[0] == B[j]? 1: 0;
		for (i = 1; i < lenA; ++i)
		for (j = 1; j < lenB; ++j) {
			cnt[i][j] = A[i] == B[j]? cnt[i- 1][j - 1] + 1: cnt[i][j - 1];
			cnt[i][j] = cnt[i][j] > cnt[i - 1][j]? cnt[i][j]:cnt[i- 1][j];
		}

		printf("%d\n", cnt[lenA - 1][lenB - 1]);
	}

	return 0;
}
