#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main (void) {
	long s, d, x;

	while (scanf("%ld %ld", &s, &d) != EOF) {
		x = (long)sqrt(2 * d + s * s);
		if ((x + s) * (x - s + 1) >= 2 * d) printf("%ld\n", x);
		else printf("%ld\n", x + 1);
	}

	return 0;
}
