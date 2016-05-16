#include <cstdio>

using namespace std;

int main (void) {
	int lower, upper, n;
	long list[7];

	lower = 8;
	upper = 13;

	list[0] = 1;
	for (n = 2; n <= lower; ++n) list[0] *= n;
	for (n = 9; n <= 13; ++n) list[n - lower] = list[n - lower - 1] * n;

	while (scanf("%d", &n) != EOF) {
		if ((n >= 0 && n < lower) || (n < 0 && (-1 * n) % 2 == 0)) printf("Underflow!\n");
		else if ((n > 0 && n > upper) || (n < 0 && (-1 * n) % 2 == 1)) printf("Overflow!\n");
		else printf("%ld\n", list[n - lower]);
	}

	return 0;
}
