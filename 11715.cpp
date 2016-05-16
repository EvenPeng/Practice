#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main (void) {
	int l, index;
	double u, v, t, s, a;

	index = 0;
	while (true) {
		scanf("%d", &l);
		if (!l) break;
		else if (l == 1) {
			scanf("%lf %lf %lf", &u, &v, &t);
			s = (u + v) * t / 2;
			a = (v - u) / t;
			printf("Case %d: %.3lf %.3lf\n", ++index, s, a);
		} else if (l == 2) {
			scanf("%lf %lf %lf", &u, &v, &a);
			t = (v - u) / a;
			s = (u + v) * t / 2;
			printf("Case %d: %.3lf %.3lf\n", ++index, s, t);
		} else if (l == 3) {
			scanf("%lf %lf %lf", &u, &a, &s);
			v = sqrt(u * u + 2 * s * a);
			t = (v - u) / a;
			printf("Case %d: %.3lf %.3lf\n", ++index, v, t);
		} else if (l == 4) {
			scanf("%lf %lf %lf", &v, &a, &s);
			u = sqrt(v * v - 2 * s * a);
			t = (v - u) / a;
			printf("Case %d: %.3lf %.3lf\n", ++index, u, t);
		}
	}

	return 0;
}
