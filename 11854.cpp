#include <cstdio>

using namespace std;

int main (void) {
	int tmpInt, a, b, c;

	while (true) {
		scanf("%d  %d  %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0) break;
		if (a > c) {
			tmpInt = a;
			a = c;
			c = tmpInt;
		}
		if (b > c) {
			tmpInt = b;
			b = c;
			c = tmpInt;
		}
		if (a * a + b * b == c * c) printf("right\n");
		else printf("wrong\n");
	}

	return 0;
}
