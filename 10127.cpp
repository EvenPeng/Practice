#include <cstdio>
#include <cmath>

using namespace std;

int main (void) {
	long num, n, total, tmpInt, i;

	while (scanf("%ld", &n) != EOF) {
		num = 1;
		total = 1;
		total %= n;
		while (total > 0) {
			i = num;
			tmpInt = 1;
			while (i > 0) {
				if (i > 9) {
					tmpInt *= pow(10, 9);
					i -= 9;
				} else {
					tmpInt *= pow(10, i);
					i = 0;
				}
				tmpInt %= n;
			}
			total += tmpInt;
			total %= n;
			num ++;
		}
		printf("%ld\n", num);
	}

	return 0;
}
