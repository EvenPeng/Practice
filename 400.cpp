#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
char str[100][100];

void sortS (int head, int len) {
	int i = head;
	int j = head + len - 1;
	char pivot[100], tmp[100];

	if (len < 2) return;
	else memcpy(pivot, str[head + len / 2], sizeof(char) * 100);

	while (true) {
		while (strcmp(str[i], pivot) < 0) ++i;
		while (strcmp(str[j], pivot) > 0) --j;
		if (i >= j) break;
		memcpy(tmp, str[i], sizeof(char) * 100);
		memcpy(str[i++], str[j], sizeof(char) * 100);
		memcpy(str[j--], tmp, sizeof(char) * 100);
	}

	sortS(head, i - head);
	sortS(i, len - i + head);
}

int main (void) {
	int i, j, k, L, C, R, head;
	char out[65];
	
	out[60] = '\0';
	while (scanf("%d\n", &N) != EOF) {
		printf("------------------------------------------------------------\n");
		L = 0;
		for (i = 0; i < N; ++i) {
			scanf("%s", str[i]);
			L = strlen(str[i]) > L? strlen(str[i]): L;
		}
		C = 62 / (L + 2);
		R = (N - 1) / C + 1;
		sortS(0, N);
		for (i = 0; i < R; ++i) {
			for (j = 0; j < 60; ++j) out[j] = ' ';
			for (j = 0; j < C; ++j) {
				head = j * (L + 2);
				for (k = 0; k < strlen(str[i + j * R]); ++k)
					out[head++] = str[i + j * R][k];
				/*
				printf("%s", str[i + j * R]);
				k = L - (int)strlen(str[i + j * R]);
				k += j < C - 1? 2: 0;
				out[k] = '\0';
				printf("%s", out);
				out[k] = ' ';
				*/
				if (i + (j + 1) * R >= N) break;
			}
			printf("%s\n", out);
		}
	}

	return 0;
}
