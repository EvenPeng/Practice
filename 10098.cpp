#include <cstdio>
#include <cstring>

using namespace std;

void sortC (char *arr, int len) {
	int i = 0;
	int j = len - 1;
	char tmpC, pivot = arr[len / 2];

	if (len < 2) return;

	while (true) {
		while (arr[i] < pivot) ++i;
		while (arr[j] > pivot) --j;
		if (i >= j) break;

		tmpC = arr[i];
		arr[i++] = arr[j];
		arr[j--] = tmpC;
	}

	sortC(arr, i);
	sortC(arr + i, len - i);
}

int main (void) {
	char arr[20], tmpC;
	int len, n, i, j, min, times;

	scanf("%d", &times);

	while (times-- > 0) {
		scanf("%s", arr);
		len = strlen(arr);
		
		sortC(arr, len);
		printf("%s\n", arr);

		while (true) {
			i = len - 1;
			while (i > 0 && arr[i] <= arr[i - 1]) --i;
			if (i > 0) {
				min = i;
				i --;
				while (min < len && arr[min] < arr[i]) ++min;
				if (min < len) {
					for (j = min + 1; j < len; ++j)
					if (arr[j] > arr[i] && arr[j] < arr[min]) min = j;

					tmpC = arr[i];
					arr[i] = arr[min];
					arr[min] = tmpC;
					
					i++;
					sortC(arr + i, len - i);
				} else sortC(arr + i, len - i);

				printf("%s\n", arr);
			} else break;
		}

		printf("\n");
	}

	return 0;
}
