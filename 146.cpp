#include <cstdio>
#include <cstring>

using namespace std;

void sortC (char *arr, int len) {
	int i, j;
	char tmpChar, pivot = arr[len / 2];

	if (len < 2) return;

	i = 0;
	j = len - 1;

	while (true) {
		while (arr[i] < pivot) ++i;
		while (arr[j] > pivot) --j;
		if (i >= j) break;

		tmpChar = arr[i];
		arr[i++] = arr[j];
		arr[j--] = tmpChar;
	}

	sortC(arr, i);
	sortC(arr + i, len - i);
}

int main (void) {
	bool flag;
	char arr[60], tmpChar;
	int i, j, index;

	while (gets(arr) && arr[0] != '#') {
		flag = false;
		for (i = strlen(arr) - 1; i > 0; --i)
			if (arr[i - 1] < arr[i]) {
				flag = true;
				break;
			}
		if (flag) {
			index = i;
			while (index < strlen(arr))
				if (arr[index] > arr[i - 1]) break;
				else index ++;
			for (j = index + 1; j < strlen(arr); ++j)
			if (arr[j] > arr[i - 1]) {
				if (arr[j] < arr[index]) index = j;
			}
			if (index == strlen(arr)) index --;
			tmpChar = arr[index];
			arr[index] = arr[i - 1];
			arr[i - 1] = tmpChar;
			sortC(arr + i, strlen(arr) - i);
			for (i = 0; i < strlen(arr); ++i) printf("%c", arr[i]);
			printf("\n");
		} else printf("No Successor\n");
	}

	return 0;
}
