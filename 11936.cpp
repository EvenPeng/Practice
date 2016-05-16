#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main (void) {
	int times, x, y, z, tmpS;

	scanf("%d", &times);

	while (times--) {
		scanf("%d %d %d", &x, &y, &z);
		if (x > z) {
			tmpS = x;
			x = z;
			z = tmpS;
		}
		if (y > z) {
			tmpS = y;
			y = z;
			z = tmpS;
		}
		if (x + y <= z) printf("Wrong!!\n");
		else printf("OK\n");
	}

	return 0;
}
