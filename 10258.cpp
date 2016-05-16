#include <cstdio>
#include <cstring>

using namespace std;

int corr[101], total[101], score[101][11];

inline int cmp(int x, int y) {
	if (corr[x] != corr[y]) return corr[x] - corr[y];
	else if (total[x] != total[y]) return total[y] - total[x];
	else return y - x;
}

void sortL (int *list, int len) {
	int i = 0;
	int j = len - 1;
	int tmpS, pivot = list[len / 2];

	if (len < 2) return;

	while (true) {
		while (cmp(list[i], pivot) > 0) ++i;
		while (cmp(list[j], pivot) < 0) --j;
		if (i >= j) break;

		tmpS = list[i];
		list[i++] = list[j];
		list[j--] = tmpS;
	}

	sortL(list, i);
	sortL(list + i, len - i);
}

int main (void) {
	bool check[101], prob[101][11];
	char str[101], stat;
	int times, i, j, list[101], lenL, l, n, t;

	scanf("%d\n", &times);

	while (times--) {
		lenL = 0;
		for (i = 1; i < 101; ++i) {
			check[i] = false;
			for (j = 1; j < 11; ++j) {
				prob[i][j] = false;
				score[i][j] = 0;
			}
			corr[i] = 0;
			total[i] = 0;
		}
		
		while (true) {
			str[0] = '\0';
			gets(str);
			if (!strlen(str)) break;
			sscanf(str, "%d %d %d %c\n", &l, &n, &t, &stat);
			check[l] = true;
			if (!prob[l][n]) {
				if (stat == 'C') {
					prob[l][n] = true;
					score[l][n] += t;
				} else if (stat == 'I') {
					score[l][n] += 20;
				}
			}
		}

		for (i = 1; i < 101; ++i)
		if (check[i]) {
			list[lenL++] = i;
			for (j = 1; j < 11; ++j)
			if (prob[i][j]) {
				corr[i] ++;
				total[i] += score[i][j];
			}
		}

		sortL(list, lenL);

		for (i = 0; i < lenL; ++i) printf("%d %d %d\n", list[i], corr[list[i]], total[list[i]]);
		if (times) printf("\n");
	}

	return 0;
}
