#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	int list[101], n;

	list[1] = 1;
	for (n = 2; n <= 100; ++n) list[n] = list[n - 1] + n * n;

	while (true) {
		scanf("%d", &n);
		if (!n) break;
		else printf("%d\n", list[n]);
	}

	return 0;
}
