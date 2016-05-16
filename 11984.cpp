#include <cstdio>

using namespace std;

int main (void) {
	double c, d;
	int times, index;

	scanf("%d", &times);
	index = 0;

	while (times-- > 0) {
		scanf("%lf %lf", &c, &d);
		printf("Case %d: %.2lf\n", ++index, c + d * 5 / 9);
	}

	return 0;
}
