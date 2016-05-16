#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	int n, m, i, org;

	while (scanf("%d", &n) != EOF) {
		org = n;
		m = n & 255;
		for (i = 1; i < 4; ++i) {
			n >>= 8;
			m = (m << 8) + (n & 255);
		}
		printf("%d converts to %d\n", org, m);
	}

	return 0;
}
