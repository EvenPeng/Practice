#include <cstdio>

using namespace std;

int main (void) {
	long n;

	while (scanf("%ld", &n) != EOF) {
		n = ((n + 1) * n) / 2;
		printf("%ld\n", n * n);
	}

	return 0;
}
