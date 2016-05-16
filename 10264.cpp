#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	int d, i, j, w, max, nei[32768];

	while (scanf("%d", &d) != EOF) {
		memset(nei, 0, sizeof(int) * (1 << d));

		for (i = 0; i < (1 << d); ++i) {
			scanf("%d", &w);
			for (j = 0; j < d; ++j) nei[i ^ (1 << j)] += w;
		}

		max = 0;
		for (i = 0; i < (1 << d); ++i)
		for (j = 0; j < d; ++j) 
		if ((i ^ (1 << j)) > i) max = nei[i ^ (1 << j)] + nei[i] > max? nei[i + (1 << j)] + nei[i]: max;
		
		printf("%d\n", max);
	}

	return 0;
}
