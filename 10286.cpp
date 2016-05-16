#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main (void) {
	double d, c;

	c = sin(M_PI * 108 / 180) / sin(M_PI * 63 / 180);
	while (scanf("%lf", &d) != EOF) printf("%.10lf\n", d * c);

	return 0;
}
