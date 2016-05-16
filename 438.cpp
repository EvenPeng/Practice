#include <cstdio>
#include <cmath>

using namespace std;

#define Pi 3.141592653589793

int main (void) {
	double x, y, x1, x2, x3, y1, y2, y3;
	double xa, xb, ya, yb, ma, mb, r;

	while (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF) {
		xa = (x1 + x2) / 2;
		ya = (y1 + y2) / 2;
		xb = (x2 + x3) / 2;
		yb = (y2 + y3) / 2;
		ma = (y2 - y1) / (x2 - x1);
		mb = (y3 - y2) / (x3 - x2);
		if (x2 - x1 == 0) {
			y = ya;
			x = xb - mb * (y - yb);
		} else if (x3 -x2 == 0) {
			y = yb;
			x = xa - ma * (y - ya);
		} else if (y3 - y2 == 0) {
			x = (ma * mb * (y1 - y3) + mb * (x1 + x2) - ma * (x2 + x3)) / (2 * (mb - ma));
			y = -1 * (x - xa) / ma + ya;
		} else {
			x = (ma * mb * (y1 - y3) + mb * (x1 + x2) - ma * (x2 + x3)) / (2 * (mb - ma));
			y = -1 * (x - xb) / mb + yb;
		}
		r = sqrt(pow(x - x1, 2) + pow(y - y1, 2));
		printf("%.2lf\n", 2 * r * Pi);
	}

	return 0;
}
