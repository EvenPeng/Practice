#include <cstdio>

using namespace std;

int main (void) {
	int times, index;
	long long int edge[3], tmpI;

	index = 0;
	scanf("%d", &times);

	while (times-- > 0) {
		scanf("%lld %lld %lld", edge, edge + 1, edge + 2);
		if (edge[0] < edge[1]) {
			tmpI = edge[0];
			edge[0] = edge[1];
			edge[1] = tmpI;
		}
		if (edge[0] < edge[2]) {
			tmpI = edge[0];
			edge[0] = edge[2];
			edge[2] = tmpI;
		}
		if (edge[1] < edge[2]) {
			tmpI = edge[1];
			edge[1] = edge[2];
			edge[2] = tmpI;
		}

		printf("Case %d: ", ++index);
		if (edge[0] <= 0 || edge[1] <= 0 || edge[2] <= 0) printf("Invalid\n");
		else if (edge[0] < edge[1] + edge[2]) {
			if (edge[0] == edge[1] && edge[1] == edge[2]) printf("Equilateral\n");
			else if (edge[0] == edge[1] || edge[1] == edge[2]) printf("Isosceles\n");
			else printf("Scalene\n");
		} else printf("Invalid\n");
	}

	return 0;
}
