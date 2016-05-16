#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	bool flag;
	int table[101], times, index, n, i, j, tmpI;

	index = 0;
	scanf("%d", &times);

	while (times-- > 0) {
		flag = true;
		memset(table, 0, sizeof(int) * 101);
		scanf("%d", &n);

		for (i = 0; i < n; ++i)
		if (flag) for (j = 0; j < n; ++j) {
			scanf("%d", &tmpI);
			table[tmpI] ++;
			flag &= table[tmpI] <= n;
		}
		else  for (j = 0; j < n; ++j) scanf("%d", &tmpI);
		
		if (flag) printf("Case %d: yes\n", ++index);
		else printf("Case %d: no\n", ++index);
	}

	return 0;
}
