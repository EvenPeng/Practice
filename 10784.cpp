#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main (void) {
	long d, n, diff;
	int index;

	index = 0;
	while (true) {
		scanf("%ld", &d);
		if (!d) break;
		n = (3 + sqrt(9 + 8 * d) ) / 2;
		if (n * (n - 3) / 2 < d) ++n;
		printf("Case %d: %ld\n", ++index, n);
	}

	return 0;
}
