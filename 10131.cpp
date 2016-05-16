#include <cstdio>
#include <cstring>

using namespace std;

struct elephant {
	int w, iq, label;
};

void sortE (elephant *list, int len) {
	int i = 0;
	int j = len - 1;
	int pivot = list[len / 2].iq;
	elephant tmpE;

	if (len < 2) return;

	while (true) {
		while (list[i].iq - pivot > 0) ++i;
		while (list[j].iq - pivot < 0) --j;
		if (i >= j) break;

		memcpy(&tmpE, list + i, sizeof(elephant));
		memcpy(list + i, list + j, sizeof(elephant));
		memcpy(list + j, &tmpE, sizeof(elephant));

		i ++;
		j --;
	}

	sortE(list, i);
	sortE(list + i, len - i);
}

int main (void) {
	int i, j, max;
	elephant list[1001];
	int len, dp[1001];

	len = 0;
	while (scanf("%d %d", &list[len].w, &list[len].iq) != EOF) {
		list[len].label = len + 1;
		len ++;
	}
	
	sortE(list, len);

	for (i = 0; i < len; ++i) dp[i] = 1;
	max = 0;
	for (i = len - 1; i > -1; --i)
	for (j = i - 1; j > -1; --j)
	if (list[i].iq < list[j].iq && list[i].w > list[j].w) {
		dp[j] = dp[i] + 1 > dp[j]? dp[i] + 1: dp[j];
		max = dp[j] > max? dp[j]: max;
	}

	printf("%d\n",max);
	i = 0;
	while (dp[i] != max) ++i;
	printf("%d\n", list[i].label);
	j = i;
	while (++i < len) {
		if (dp[i] == dp[j] - 1 && list[i].iq < list[j].iq && list[i].w > list[j].w) {
			printf("%d\n", list[i].label);
			j = i;
		}
	}

	return 0;
}
