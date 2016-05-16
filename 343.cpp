#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	char num1[30], num2[30];
	int i, j, base1, base2, len1, len2;
	int map[130];
	long x, y;

	for (i = 0; i < 10; ++i) map['0' + i] = i;
	for (i = 0; i < 26; ++i) map['A' + i] = i + 10;

	while (scanf("%s %s", num1, num2) != EOF) {
		len1 = strlen(num1);
		len2 = strlen(num2);
		base1 = 2;
		for (i = 0; i < len1; ++i) if (base1 <= map[num1[i]]) base1 = map[num1[i]] + 1;
		base2 = 2;
		for (i = 0; i < len2; ++i) if (base2 <= map[num2[i]]) base2 = map[num2[i]] + 1;
		x = map[num1[0]];
		for (i = 1; i < len1; ++i) {
			x *= base1;
			x += map[num1[i]];
		}
		y = map[num2[0]];
		for (i = 1; i < len2; ++i) {
			y *= base2;
			y += map[num2[i]];
		}
		while (base1 < 37 && base2 < 37) {
			if (y > x) {
				base1 ++;
				x = map[num1[0]];
				for (i = 1; i < len1; ++i) {
					x *= base1;
					x += map[num1[i]];
				}
			} else if (x > y) {
				base2 ++;
				y = map[num2[0]];
				for (i = 1; i < len2; ++i) {
					y *= base2;
					y += map[num2[i]];
				}
			} else break;
		}
		if (base1 == 37 || base2 == 37) printf("%s is not equal to %s in any base 2..36\n", num1, num2);
		else printf("%s (base %d) = %s (base %d)\n", num1, base1, num2, base2);
	}

	return 0;
}
