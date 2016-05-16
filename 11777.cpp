#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	int times, i, sum, tmpI, test1, test2, index;

	index = 0;
	scanf("%d", &times);

	while (times--) {
		scanf("%d", &sum);
		for (i = 0; i < 3; ++i) {
			scanf("%d", &tmpI);
			sum += tmpI;
		}
		scanf("%d %d %d", &test1, &test2, &tmpI);
		if (test1 > test2) test2 = tmpI > test2? tmpI: test2;
		else test1 = tmpI > test1? tmpI: test1;
		sum += (test1 + test2) / 2;
		printf("Case %d: ", ++index);
		if (sum >= 90) printf("A\n");
		else if (sum >= 80) printf("B\n");
		else if (sum >= 70) printf("C\n");
		else if (sum >= 60) printf("D\n");
		else if (sum < 60) printf("F\n");
		else printf("\n");
	}

	return 0;
}
