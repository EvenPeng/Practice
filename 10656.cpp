#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	bool first;
	int i, n, tmp;

	while (scanf("%d", &n) != EOF) {
		if (!n) break;

		first = true;
		for (i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			if (tmp) {
				printf("%d", tmp);
				first = false;

				break;
			}
		}

		if (!first)
			for (++i; i < n; ++i) {
				scanf("%d", &tmp);
				if (tmp) printf(" %d", tmp);
			}

		if (first) printf("0\n");
		else printf("\n");
	}

	return 0;
}
