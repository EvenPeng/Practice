#include <cstdio>
#include <cstring>

using namespace std;

int len;
char str[100];

inline bool check (int p) {
	int i, j;

	for (i = 0; i < p; ++i)
	for (j = i; j < len; j += p)
	if (str[i] != str[j]) return false;

	return true;
}

int main (void) {
	int times, period, i;

	scanf("%d", &times);

	while (times--) {
		scanf("%s", str);
		len = strlen(str);
		period = len;

		for (i = 1; i < period; ++i)
		if (len % i == 0 && check(i)) period = i;

		if (times) printf("%d\n\n", period);
		else printf("%d\n", period);
	}

	return 0;
}
