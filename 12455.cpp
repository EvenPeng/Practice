#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	int acc[1000001], times, n, p, len, i;

	scanf("%d", &times);

	while (times--) {
		scanf("%d %d", &n, &p);
		memset(acc, 0, sizeof(int) * (n + 1));
		
		while (p--) {
			scanf("%d", &len);
			for (i = n; i > len; --i)
				acc[i] = acc[i - len] + len > acc[i]? acc[i - len] + len: acc[i];
			acc[len] = len;
		}

		if (acc[n] == n) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
