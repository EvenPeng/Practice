#include <cstdio>
#include <cstring>

using namespace std;

struct job {
	int label;
	double price;
};

static inline double cmp (job *x, job *y) {
	if (x->price == y->price) return (double)(y->label - x->label);
	else return x->price - y->price;
}

void sortL (job *list, int len) {
	int i = 0;
	int j = len - 1;
	job pivot, tmpS;

	if (len < 2) return;
	memcpy(&pivot, list + len / 2, sizeof(job));

	while (true) {
		while (cmp(list + i, &pivot) > 0) ++i;
		while (cmp(list + j, &pivot) < 0) --j;
		if (i >= j) break;

		memcpy(&tmpS, list + i, sizeof(job));
		memcpy(list + i, list + j, sizeof(job));
		memcpy(list + j, &tmpS, sizeof(job));

		i ++;
		j --;
	}

	sortL(list, i);
	sortL(list + i, len - i);
}

int main (void) {
	int times, len, i, elapse, value;
	job list[1000];

	scanf("%d", &times);

	while (times-- > 0) {
		scanf("%d", &len);

		for (i = 0; i < len; ++i) {
			list[i].label = i + 1;
			scanf("%d %d", &elapse, &value);
			list[i].price = 1.0 * value / elapse;
		}

		sortL(list, len);

		printf("%d", list[0].label);
		for (i = 1; i < len; ++i) printf(" %d", list[i].label);
		if (times > 0) printf("\n\n");
		else printf("\n");
	}

	return 0;
}
