#include <cstdio>

using namespace std;

int main (void) {
	int index, times, len, ans, tmpI, i;

	index = 0;
	scanf("%d", &times);

	while (times-- > 0) {
		scanf("%d", &len);

		for (i = 0; i < len; ++i)
		if (i == len / 2) scanf("%d", &ans);
		else scanf("%d", &tmpI);

		printf("Case %d: %d\n", ++index, ans);
	}

	return 0;
}
