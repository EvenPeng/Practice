#include <cstdio>

using namespace std;

int main (void) {
	int n;

	while (true) {
		scanf("%d", &n);
		if (n < 0) break;
		else if (n < 2) printf("0%%\n");
		else printf("%ld%%\n", (long)n * 25);
	}

	return 0;
}
