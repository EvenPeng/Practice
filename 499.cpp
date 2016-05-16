#include <cstdio>

using namespace std;

int main (void) {
	bool init;
	int i, cnt[52], max;
	char c;

	init = true;

	while (scanf("%c", &c) != EOF) {
		if (init) {
			for (i = 0; i < 52; ++i) cnt[i] = 0;
			init = false;
		}
		if (c == '\n') {
			init = true;
			max = 0;
			for (i = 0; i < 52; ++i) max = cnt[i] > max? cnt[i]: max;
			for (i = 0; i < 26; ++i)
				if (cnt[i] == max) printf("%c", 'A' + i);
			for (i = 26; i < 52; ++i)
				if (cnt[i] == max) printf("%c", 'a' + i - 26);
			printf(" %d\n", max);
		} else if ('A' <= c && c <= 'Z') cnt[c - 'A'] ++;
		else if ('a' <= c && c <= 'z') cnt[c - 'a' + 26] ++;
	}

	return 0;
}
