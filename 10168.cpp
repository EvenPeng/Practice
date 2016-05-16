#include <cstdio>
#include <cstring>

using namespace std;

struct pair {
	bool f;
	int x, y;
} list[5000002];

int lenP, prime[1000000], square[1000000];

int main (void) {
	bool flag;
	int i, j, k, n, head, index;

	lenP = 1;
	prime[0] = 2;
	square[0] = 4;
	for (i = 3; i <= 5000000; ++i) list[i].f = false;
	list[2].f = true;
	list[2].x = 2;
	list[2].y = 2;
	head = 3;

	for (i = 3; head < 5000000; i += 2) {
		for (j = 0, flag = true; square[j] <= i; ++j)
			if (i % prime[j] == 0) {
				flag = false;
				break;
			}

		if (flag) {
			prime[lenP] = i;
			square[lenP] = i * i;

			for (j = lenP; j > 0; --j) {
				index = (i + prime[j]) / 2;
				if (index > 4999999) continue;
				else if (index < head) break;
				else if (!list[index].f) {
					list[index].f = true;
					list[index].x = prime[j];
					list[index].y = i;
				}
			}

			lenP ++;
			while (list[head].f) ++head;
		}
	}

	while (scanf("%d", &n) != EOF) {
		if (n < 8) printf("Impossible.\n");
		else if (n % 2) printf("2 3 %d %d\n", list[(n - 5) / 2].x, list[(n - 5) / 2].y);
		else printf("2 2 %d %d\n", list[(n - 4) / 2].x, list[(n - 4) / 2].y);
	}

	return 0;
}
