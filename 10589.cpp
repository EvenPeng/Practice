#include <cstdio>
#include <cmath>

using namespace std;

int main (void) {
	int n, m, i;
	double r, r2, x, x2, y, y2, outbound;

	while (true) {
		scanf("%d %lf", &n, &r);
		if (n == 0 && r == 0) break;
		r2 = r * r;
		outbound = (1.0 - sqrt(3.0) / 2) * r;
		m = 0;
		for (i = 0; i < n; ++i) {
			scanf("%lf %lf", &x, &y);
			x2 = (r - x);
			y2 = (r - y);
			if (x < outbound || x2 < outbound || y < outbound || y2 < outbound) continue;
			x2 *= x2;
			y2 *= y2;
			if (x2 + y2 > r2) continue;
			x *= x;
			if (x + y2 > r2) continue;
			y *= y;
			if (x + y > r2) continue;
			if (x2 + y > r2) continue;
			m ++;
		}
		printf("%.5lf\n", m * r2 / n);
	}

	return 0;
}
