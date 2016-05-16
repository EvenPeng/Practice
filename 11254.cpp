#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main (void) {
	long long goal, l, r, n, m, ll, lr;

	while (true) {
		scanf("%lld", &goal);
		if (goal < 0) break;
		lr = goal;
		ll = goal;
		goal *= 2;
		
		for (n = (long long)sqrt(goal); n > 1; --n) {
			if (goal % n == 0) {
				m = goal / n;
				if ((m - n + 1) % 2 == 1) continue;
				l = (m - n + 1) / 2;
				r = (m + n - 1) / 2;
				if (n - 1 > lr - ll) {
					lr = r;
					ll = l;
				}
				break;
			}
		}

		printf("%lld = %lld + ... + %lld\n", goal / 2, ll, lr);
	}

	return 0;
}
