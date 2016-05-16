#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <cstring>

using namespace std;

struct Node {
	double x, y;
};

int main (void) {
	int i, j, k, times, len, done, minIndex;
	Node list[101], tmpN;
	double sum, min, tmpD;

	scanf("%d", &times);

	while (times-- > 0) {
		scanf("%d", &len);
		for (i = 0; i < len; ++i) scanf("%lf %lf", &list[i].x, &list[i].y);

		sum = 0;
		done = 1;
		for (i = 1; i < len; ++i) {
			min = DBL_MAX;
			for (j = 0; j < done; ++j)
			for (k = done; k < len; ++k) {
				tmpD = pow(list[j].x - list[k].x, 2) + pow(list[j].y - list[k].y, 2);
				if (tmpD < min) {
					min = tmpD;
					minIndex = k;
				}
			}
			sum += sqrt(min);
			memcpy(&tmpN, list + done, sizeof(Node));
			memcpy(list + done, list + minIndex, sizeof(Node));
			memcpy(list + minIndex, &tmpN, sizeof(Node));
			done ++;
		}

		printf("%.2lf\n", sum);
		if (times > 0) printf("\n");
	}

	return 0;
}
