#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void tran (int x) {
	if (x / 16 > 0) tran(x / 16);
	x %= 16;
	if (x < 10) printf("%d", x);
	else printf("%c", (char)('A' + x - 10));
}

int main (void) {
	int n, i, map[130];
	char str[30];

	for (i = 0; i < 10; ++i) map[(int)'0' + i] = i;
	for (i = 0; i < 6; ++i) map[(int)'A' + i] = 10 + i;

	while (true) {
		scanf("%s", str);
		if (str[0] == '-') break;
		else if (str[0] == '0' && str[1] == 'x') {
			n = map[str[2]];
			for (i = 3; i < strlen(str); ++i) {
				n *= 16;
				n += map[str[i]];
			}
			printf("%d\n", n);
		} else {
			n = atoi(str);
			printf("0x");
			tran(n);
			printf("\n");
		}
	}

	return 0;
}
