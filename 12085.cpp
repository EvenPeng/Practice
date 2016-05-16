#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char num[100001][20];

int main (void) {
	int cases, len, i, j, index;

	cases = 1;

	while (scanf("%d", &len) != EOF && len > 0) {
		for (i = 0; i < len; ++i)
			scanf("%s", &num[i][0]);
	
		printf("Case %d:\n", cases++);

		index = 0;
		printf("%s", num[0]);
		for (i = 1; i < len; ++i) {
			if (atoi(num[i]) - atoi(num[i - 1]) > 1) {
				if (index != i - 1) {
					j = 0;
					while (num[index][j] == num[i - 1][j]) j++;
					printf("-");
					while (j < strlen(num[index])) printf("%c", num[i - 1][j++]);
				}
				printf("\n%s", num[i]);
				index = i;
			}
		}
		if (index != i - 1) {
			j = 0;
			while (num[index][j] == num[i - 1][j]) j++;
			printf("-");
			while (j < strlen(num[index])) printf("%c", num[i - 1][j++]);
		}
		printf("\n\n");
	}

	return 0;
}
