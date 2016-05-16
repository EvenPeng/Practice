#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	long long n, t, ans;

	while (true) {
		scanf("%lld %lld", &n, &t);
		if (!n && !t) break;
		if (n == 1 || t == 100) printf("Not found\n"); 
		else {
			ans = (n - 1) * 100 / (100 - t);
			if ((n - 1) * 100 % (100 - t) == 0) ans --;
			if (ans >= n) printf("%lld\n", ans);
			else printf("Not found\n");
		}
	}

	return 0;
}
