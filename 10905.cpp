#include <cstdio>
#include <cstring>

using namespace std;

char head[51][1000];
int list[51], len[51];

int cmp (int x, int y) {
	int i, j;

	for(i = 0; i < len[x] && i < len[y] ; ++i)
	if (head[x][i] != head[y][i]) return head[y][i] - head[x][i];

	if (len[x] > len[y]) {
		for(i = 0, j = 0; j < len[y] ; ++i, ++j)
		if (head[x][i] != head[y][j]) return head[y][j] - head[x][i];
		for(j = 0; i < len[x] ; ++i, ++j)
		if (head[x][i] != head[x][j]) return head[x][j] - head[x][i];
		for(i = 0; j < len[x] ; ++i, ++j)
		if (head[y][i] != head[x][j]) return head[x][j] - head[y][i];
	} else if (len[x] < len[y]) {
		for(i = 0, j = 0; i < len[x] ; ++i, ++j)
		if (head[x][i] != head[y][j]) return head[y][j] - head[x][i];
		for(i = 0; j < len[y] ; ++i, ++j)
		if (head[y][i] != head[y][j]) return head[y][j] - head[y][i];
		for(j = 0; i < len[y] ; ++i, ++j)
		if (head[y][i] != head[x][j]) return head[x][j] - head[y][i];
	}
	
	return 0;
}

void sortH (int *order, int len) {
	int i = 0;
	int j = len - 1;
	int tmpI, pivot = order[len / 2];

	if (len < 2) return;

	//for (int x = 0; x < len; ++x) printf("%s ", head[order[x]]);
	//printf("\n");

	while (true) {
		while (cmp(order[i], pivot) < 0) ++i;
		while (cmp(order[j], pivot) > 0) --j;
		if (i >= j) break;
		tmpI = order[i];
		order[i++] = order[j];
		order[j--] = tmpI;
	}

	//for (int x = 0; x < len; ++x) printf("%s ", head[order[x]]);
	//printf("\n");

	sortH(order, i);
	sortH(order + i, len - i);
}

int main (void) {
	int n, i, order[51];

	while (true) {
		scanf("%d\n", &n);
		if (!n) break;

		for (i = 0; i < n; ++i) {
			order[i] = i;
			scanf("%s", &head[i][0]);
			len[i] = strlen(head[i]);
		}

		sortH(order, n);

		//for (i = 0; i < n; ++i) printf("%s - ", head[order[i]]);
		//printf("\n");
		for (i = 0; i < n; ++i) printf("%s", head[order[i]]);
		printf("\n");
	}

	return 0;
}
