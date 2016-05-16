#include <cstdio>

using namespace std;

void sortC (int *cnt, char *arr, int len) {
	char tmpChar;
	int i, j, tmpInt;
	char pivot = arr[len / 2];
	
	if (len < 2) return;

	i = 0;
	j = len - 1;
	while (true) {
		while (arr[i] < pivot) ++i;
		while (arr[j] > pivot) --j;
		if (i >= j) break;

		tmpInt = cnt[i];
		cnt[i] = cnt[j];
		cnt[j] = tmpInt;
		tmpChar = arr[i];
		arr[i++] = arr[j];
		arr[j--] = tmpChar;
	}

	sortC(cnt, arr, i);
	sortC(cnt + i, arr + i, len - i);
}

void sortN (int *cnt, char *arr, int len) {
	char tmpChar;
	int i, j, tmpInt;
	int pivot = cnt[len / 2];
	
	if (len < 2) return;

	i = 0;
	j = len - 1;
	while (true) {
		while (cnt[i] > pivot) ++i;
		while (cnt[j] < pivot) --j;
		if (i >= j) break;

		tmpInt = cnt[i];
		cnt[i] = cnt[j];
		cnt[j] = tmpInt;
		tmpChar = arr[i];
		arr[i++] = arr[j];
		arr[j--] = tmpChar;
	}

	sortN(cnt, arr, i);
	sortN(cnt + i, arr + i, len - i);
}

int main (void) {
	int cnt[26], i, j;
	char c, arr[26];

	for (i = 0; i < 26; ++i) {
		cnt[i] = 0;
		arr[i] = 'A' + i;
	}

	while (scanf("%c", &c) != EOF) {
		if ('a' <= c && c <= 'z') cnt[c - 'a'] ++;
		else if ('A' <= c && c <= 'Z') cnt[c - 'A'] ++;
	}

	sortN(cnt, arr, 26);
	for (i = 0, j = 0; i < 26 && cnt[i] > 0; ++i)
	if (cnt[i] != cnt[j]) {
		sortC(cnt + j, arr + j, i - j);
		for (; j < i; ++j) printf("%c %d\n", arr[j], cnt[j]);
		j = i;
	}
	if (cnt[j] > 0) {
		sortC(cnt + j, arr + j, i - j);
		for (; j < i; ++j) printf("%c %d\n", arr[j], cnt[j]);
		j = i;
	}

	return 0;
}
