#include <cstdio>

using namespace std;

int main (void) {
	int times, i, n, step, next;
	int list[6];
	long long sum;

	list[0] = 0;
	list[1] = 1;
	list[2] = 3;
	list[3] = 5;
	list[4] = 8;
	list[5] = 10;

	scanf("%d", &times);

	while (times-- > 0) {
		scanf("%d", &n);
		if (n < 6) {
			if (n > -1) printf("%d\n", list[n]);
			else printf("0\n");
		} else {
			sum = 0;
			for (step = 1; ; ++step) {
				i = n / step;
				next = n / (step + 1);
				if (i > next) sum += step * (i - next);
				else break;
			}
			for (i = 1; i <= next; ++i)	sum += n / i;
			printf("%lld\n", sum);
		}
	}

	return 0;
}
