#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	bool hash[20001], flag;
	int n, len, i, j, list[101], index;

	index = 0;
	while (scanf("%d", &n) != EOF) {
		len = 0;
		while (n --) scanf("%d", list + len++);
		if (list[0] < 1) flag = false;
		else {
			flag = true;
			memset(hash, false, sizeof(bool) * 20001);
			for (i = 1; flag && i < len; ++i) {
				if (list[i] <= list[i - 1]) flag = false;
				else for (j = 0; j <= i; ++j)
				if (!hash[list[i] + list[j]]) hash[list[i] + list[j]] = true;
				else flag = false;
			}
		}
		if (flag) printf("Case #%d: It is a B2-Sequence.\n\n", ++index);
		else printf("Case #%d: It is not a B2-Sequence.\n\n", ++index);
	}

	return 0;
}
