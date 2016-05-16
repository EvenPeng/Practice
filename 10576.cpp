#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	int s, d, list[12], i, j, sum;

	while (scanf("%d %d", &s, &d) != EOF) {
		d *= -1;
		for (i = 0; i < 4; ++i) list[i] = s;
		list[4] = d;
		sum = 4 * s + d;
		for (i = 3; i > -1 && sum > 0; --i) {
			list[i] = d;
			sum -= s - d;
		}
		for (i = 5; i < 12; ++i) {
			sum -= list[i - 5];
			if (sum + s < 0) list[i] = s;
			else list[i] = d;
			sum += list[i];
		}

		sum = 0;
		for (i = 0; i < 12; ++i) sum += list[i];
		if (sum > 0) printf("%d\n", sum);
		else printf("Deficit\n");
	}

	return 0;
}
