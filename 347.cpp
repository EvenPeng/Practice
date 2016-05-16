#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool check[10];
int d[10], len, list[10000];

static void verify (int l) {
	bool table[10];
	int i;

	memset(table, true, sizeof(table));

	i = 0;
	while (table[i]) {
		table[i] = false;
		i = (i + d[i]) % l;
	}

	if (i > 0) return;
	for (i = 0; i < l; ++i) if (table[i]) return;

	if (i == l) {
		list[len] = d[0];
		for (i = 1; i < l; ++i) {
			list[len] *= 10;
			list[len] += d[i];
		}
		len ++;
	}
}

void next (int l) {
	int i;

	if (l > 1) verify(l);
	if (l > 6) return;

	for (i = 1; i < 10; ++i) if (check[i]) {
		check[i] = false;
		d[l] = i;
		next(l + 1);
		check[i] = true;
	}
}

int main (void) {
	int i, j, m, n, index;

	memset(check, true, sizeof(check));

	len = 0;
	next(0);
	sort(list, list + len);

	index = 0;
	while (true) {
		scanf("%d", &n);
		if (!n) break;

		i = -1;
		j = len;
		while (j - i > 1) {
			m = (i + j) / 2;
			if (n < list[m]) j = m;
			else if (n > list[m]) i = m;
			else break;
		}
		while (list[m] < n) m ++;

		printf("Case %d: %d\n", ++index, list[m]);
	}

	return 0;
}
