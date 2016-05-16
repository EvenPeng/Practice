#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct str{
	char l[31];
	bool operator<(str other) const {
		return strcmp(l, other.l) < 0;
	}
} list[1000001];

int main (void) {
	int times, len, i, j;

	scanf("%d\n", &times);
	
	while (times--) {
		len = 0;

		while (gets(list[len].l) != NULL && strlen(list[len].l)) ++len;
		sort(list, list + len);

		j = 0;
		for (i = 1; i < len; ++i) 
		if (strcmp(list[i].l, list[j].l)) {
			printf("%s %.4lf\n", list[j].l, 100.0 * (i - j) / len);
			j = i;
		}
		if (strcmp(list[i].l, list[j].l))
			printf("%s %.4lf\n", list[j].l, 100.0 * (i - j) / len);
		if (times) printf("\n");
	}

	return 0;
}
