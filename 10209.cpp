#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main (void) {
	double r, x, y, z;

	x = M_PI / 3 + 1 - sqrt(3.0);
	y = M_PI / 3 + sqrt(3.0) * 2 - 4;
	z = 4 - M_PI * 2 / 3 - sqrt(3.0);
	while (scanf("%lf", &r) != EOF) {
		r *= r;
		printf("%.3lf %.3lf %.3lf\n", x * r, y * r, z * r);
	}

	return 0;
}
