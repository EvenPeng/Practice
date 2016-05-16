#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main (void) {
	double n, k, i, sum;

	while (scanf("%lf %lf", &n, &k) != EOF) {
		if (k > n / 2) k = n - k;
		sum = 1e-6;
		for (i = 1; i <= k; ++i, --n) sum += log10(n) - log10(i);
		printf("%.0lf\n", ceil(sum));
	}

	return 0;
}
