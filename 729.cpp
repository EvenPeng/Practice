#include <cstdio>
#include <cstring>

using namespace std;

char word[17];

int cb (unsigned int u) {
	unsigned int uCount;
    
    uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
	uCount = ((uCount + (uCount >> 3)) & 030707070707) % 63;

	return uCount;
}

inline void show (int x, int b) {
	while (b--) {
		word[b] = x & 1? '1': '0';
		x >>= 1;
	}

	printf("%s\n", word);
}

int main (void) {
	int times, n, h, i, j, k, mask, list[17][100000], len[17];

	for (i = 1; i < 17; ++i) len[i] = 0;
	len[0] = 1;
	list[0][0] = 0;
	mask = 1;
	for (i = 1; i < 17; ++i) {
		for (j = i; j > 0; --j)
		for (k = 0; k < len[j - 1]; ++k)
		list[j][len[j]++] = list[j - 1][k] + mask;
		mask <<= 1;
	}

	scanf("%d", &times);
	while (times --) {
		scanf("%d %d", &n, &h);
		j = 1 << n;
		word[n] = '\0';
		for (i = 0; i < len[h] && list[h][i] < j; ++i) show(list[h][i], n);
		if (times) printf("\n");
	}

	return 0;
}
