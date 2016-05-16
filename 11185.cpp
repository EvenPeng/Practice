#include <cstdio>

using namespace std;

int main (void) {
	int n, digit[100], len;

	while (true) {
		scanf("%d", &n);
		if (n < 0) break;

		if (n == 0) {
			printf("0\n");
			continue;
		}

		len = 0;
		while (n > 0) {
			digit[len++] = n % 3;
			n /= 3;
		}
		
		len--;
		for (; len > -1; --len) printf("%d", digit[len]);
		printf("\n");
	}

	return 0;
}
