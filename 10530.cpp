#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	int upper, lower, tmpI;
	char w1[10], w2[10];

	upper = 11;
	lower = 0;
	while (true) {
		scanf("%d", &tmpI);
		if (!tmpI) break;

		scanf("%s %s", w1, w2);
		if (w1[0] == 't') {
			if (w2[0] == 'h') upper = tmpI < upper? tmpI: upper;
			else lower = tmpI > lower? tmpI: lower;
		} else {
			if (lower < tmpI && tmpI < upper) printf("Stan may be honest\n");
			else printf("Stan is dishonest\n");
			upper = 11;
			lower = 0;
		}
	}

	return 0;
}
