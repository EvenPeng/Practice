#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	int times, len, diff, seg, max, tmpI, i;

	scanf("%d", &times);

	while (times--) {
		scanf("%d", &len);

		seg = -300001;
		scanf("%d", &max);
		for (i = 1; i < len; ++i) {
			scanf("%d", &tmpI);
			diff = max - tmpI;
			if (diff > seg) seg = diff;
			if (diff < 0) max = tmpI;
		}

		printf("%d\n", seg);
	}

	return 0;
}
