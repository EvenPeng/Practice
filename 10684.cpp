#include <cstdio>

using namespace std;

int main (void) {
	int n, i, max,tmpI, curr;

	while (true) {
		scanf("%d", &n);
		if (n < 1) break;

		max = 0;
		curr = 0;
		for (i = 0; i < n; ++i)	{
			scanf("%d", &tmpI);
			curr += tmpI;
			if (curr < 0) curr = 0;
			max = curr > max? curr: max;
		}

		if (max > 0) printf("The maximum winning streak is %d.\n", max);
		else printf("Losing streak.\n");
	}

	return 0;
}
