#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main (void) {
	int times, h, m, all;
	int hh[13] = {0, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 12, 11};

	scanf("%d", &times);

	while (times--) {
		scanf("%d:%d", &h, &m);
		if (h == 12) h = 0;
		all = abs(h * 60 + m - 720);
		printf("%02d:%02d\n", all / 60 == 0? 12: all / 60, all % 60);
	}

	return 0;
}
