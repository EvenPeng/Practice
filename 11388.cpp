#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	int times, G, L;

	scanf("%d", &times);
	while (times--) {
		scanf("%d %d", &G, &L);
		if (G > L) printf("-1\n");
		else if (L % G) printf("-1\n");
		else printf("%d %d\n", G, L);
	}

	return 0;
}
