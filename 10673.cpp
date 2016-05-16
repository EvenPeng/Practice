#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	int times;
	long x, k, p, q;

	scanf("%d", &times);
	while (times--) {
		scanf("%ld %ld", &x, &k);
		p = x / k;
		q = x % k? p + 1: p;
		if (!p) printf("0 %ld\n", x < k? x: k);
		else printf("%ld %ld\n", x / p - x % p, x % p);
	}

	return 0;
}
