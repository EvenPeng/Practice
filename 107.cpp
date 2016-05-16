#include <cstdio>
#include <cmath>

using namespace std;

int main (void) {
	long h, l, sum, cnt, n, m, step;
	double k, diff;

	while (true) {
		scanf("%ld %ld", &h, &l);
		if (h == 0 && l == 0) break;
		if (l == 1) {
			sum = h;
			cnt = 0;
			while (h > 1) {
				cnt ++;
				h /= 2;
				sum += h;
			}
			printf("%ld %ld\n", cnt, sum);
			continue;
		}

		n = 1;
		do {
			n ++;
			diff = log(n + 1) / log(n) - log (h) / log(l);
		} while (diff > 1.0e-9);
		
		k = log(1.0 * h) / log(n + 1.0);

		cnt = 0;
		sum = h;
		m = 0;
		while (h > 1) {
			cnt += pow(n, m);
			m ++;
			h /= n + 1;
			sum += pow(n, m) * h;
		}

		printf("%ld %ld\n", cnt, sum);
	}

	return 0;
}
