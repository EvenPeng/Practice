#include <cstdio>

using namespace std;

void sortL (int *arr, int len) {
	int i = 0;
	int j = len - 1;
	int tmpInt, pivot = arr[len / 2];

	if (len < 2)
		return ;

	while (true) {
		while (arr[i] < pivot) ++i;
		while (arr[j] > pivot) --j;
		if (i >= j) break;

		tmpInt = arr[i];
		arr[i++] = arr[j];
		arr[j--] = tmpInt;
	}

	sortL(arr, i);
	sortL(arr + i, len - i);
}

int main (void) {
	char c;
	int i, j, k, len, list[31], sortlist[31];
	int index, tmpInt;

	while (scanf("%d", list) != EOF) {
		len = 1;
		while (scanf("%c", &c) != EOF && c == ' ')
			scanf("%d", &list[len ++]);
			
		for (i = 0; i < len; ++i) {
			if (i > 0) printf(" ");
			printf("%d", list[i]);
			sortlist[i] = list[i];
		}
		printf("\n");

		sortL(sortlist, len);

		for (i = len - 1; i > 0; --i) {
			if (list[i] == sortlist[i]) continue;
			
			index = i;
			while (index > 0)
				if (list[--index] == sortlist[i]) break;

			if (index != 0) {
				printf("%d ", len - index);
				j = 0;
				k = index;
				while (j < k) {
					tmpInt = list[j];
					list[j++] = list[k];
					list[k--] = tmpInt;
				}
			}
			
			printf("%d ", len - i);
			j = 0;
			k = i;
			while (j < k) {
				tmpInt = list[j];
				list[j++] = list[k];
				list[k--] = tmpInt;
			}
		}

		printf("0\n");
	}
}
