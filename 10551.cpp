#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	char pc[1002], mc[12];
	int b, i, conver[128];
	long p, m;

	for (b = 0; b < 10; ++b) conver[b + '0'] = b;

	while (true) {
		scanf("%d", &b);
		if (!b) break;

		scanf("%s %s", pc, mc);
		m = 0;
		for (i = 0; i < strlen(mc); ++i)
			m = m * b + conver[mc[i]];

		p = 0;
		for (i = 0; i < strlen(pc); ++i) {
			p = p * b + conver[pc[i]];
			p %= m;
		}

		if (p > 0) {
			pc[9] = '\0';
			for (i = 1; p > 0; ++i) {
				pc[9 - i] = '0' + p % b;
				p /= b;
			}

			printf("%s\n", pc + 10 - i);
		} else printf("0\n");
	}

	return 0;
}
