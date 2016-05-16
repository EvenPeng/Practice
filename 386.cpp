#include <cstdio>
#include <cmath>

using namespace std;

int main (void) {
	int list[201], a, b, c, d, i, j, tmpI;

	for (a = 0; a < 6; ++a) list[a] = pow(a, 3);
	for (a = 6; a < 201; ++a) {
		list[a] = pow(a, 3);
		for (b = 2; b < a - 2; ++b)
		for (c = b + 1; c < a - 1; ++c) {
			tmpI = list[a] - list[b] - list[c];
			i = c;
			j = a;
			while (j - i > 1) {
				d = (i + j) / 2;
				if (tmpI < list[d]) j = d;
				else if (tmpI > list[d]) i = d;
				else break;
			}
			if (list[d] == tmpI) printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
		}
	}

	return 0;
}
