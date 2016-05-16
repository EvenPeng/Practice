#include <cstdio>

using namespace std;

int n, d, list[31][11], label[31], max[31], MAX, g[31][31];

int comp (int x, int y) {
	int i;

	if (list[x][d] < list[y][d]) return -1;
	else if (list[x][d] > list[y][d]) return 1;

	for (i = 0; i < d; ++i)
	if (list[x][i] < list[y][i]) return -1;
	else if (list[x][i] > list[y][i]) return 1;

	return 0;
}

void sortH (int head, int len) {
	int i = 0;
	int j = len - 1;
	int tmpI, pivot = label[head + len / 2];

	if (len < 2) return;

	while (true) {
		while (comp(label[head + i], pivot) < 0) ++i;
		while (comp(label[head + j], pivot) > 0) --j;
		if (i >= j) break;

		tmpI = label[head + i];
		label[head + i++] = label[head + j];
		label[head + j--] = tmpI;
	}

	sortH(head, i);
	sortH(head + i, len - i);
}

void sortL (int *arr, int len) {
	int i = 0;
	int j = len - 1;
	int tmpI, pivot = arr[len / 2];

	if (len < 2) return;

	while (true) {
		while (arr[i] < pivot) ++i;
		while (arr[j] > pivot) --j;
		if (i >= j) break;

		tmpI = arr[i];
		arr[i++] = arr[j];
		arr[j--] = tmpI;
	}

	sortL(arr, i);
	sortL(arr + i, len - i);
}

bool check (int x, int y) {
	int i;

	for (i = 0; i < d; ++i)
	if (list[label[x]][i] >= list[label[y]][i])
		return false;

	return true;
}

int main (void) {
	int i, j, k, index;

	while (scanf("%d %d", &n, &d) != EOF) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) g[i][j] = 1;
			label[i] = i;
			max[i] = 1;
			list[i][d] = 0;
			for (j = 0; j < d; ++j) {
				scanf("%d", &list[i][j]);
				list[i][d] += list[i][j];
			}
			sortL(&list[i][0], d);
		}
		sortH(0, n);

		MAX = 1;
		for (i = n - 1; i > -1; --i) {
			for (j = i + 1; j < n; ++j)
			if (check(i, j)) {
				g[i][j] = max[j] + 1;
				if (max[i] < g[i][j]) max[i] = g[i][j];
				if (MAX < g[i][j]) MAX = g[i][j];
			}
		}

		/*
		printf("   ");
		for (i = 0; i < n; ++i) printf("%3d", max[i]);
		printf("\n");
		printf("   ");
		for (i = 0; i < n; ++i) printf("%3d", label[i] + 1);
		printf("\n");
		for (i = 0; i < n; ++i) {
			printf("%3d", label[i] + 1);
			for (j = 0; j < n; ++j) printf("%3d", g[i][j]);
			printf("\n");
		}
		printf(" - - -\n");

		for (i = 0; i < n; ++i) {
			printf("%2d %2d - ", label[i] + 1, max[i]);
			for (j = 0; j <= d; ++j) printf("%d\t", list[label[i]][j]);
			printf("\n");
		}
		*/

		printf("%d\n", MAX);
		index = 0;
		while (max[index] != MAX) ++index;
		printf("%d", label[index] + 1);
		for (i = MAX; i > 1; i--) {
			for (j = index + 1; g[index][j] != i; ++j);
			printf(" %d", label[j] + 1);
			index = j;
		}
		printf("\n");
	}

	return 0;
}
