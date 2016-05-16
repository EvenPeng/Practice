#include <cstdio>

using namespace std;

int pattern[10][3] = {
	{0,0,0},
	{1,0,0},
	{2,0,0},
	{3,0,0},
	{1,1,0},
	{0,1,0},
	{1,1,0},
	{2,1,0},
	{3,1,0},
	{1,0,1}};
int cnt[101][5];
char sym[] = {'i', 'v', 'x', 'l', 'c'};

int main (void) {
	int n, i, d1, d2;

	for (n = 0; n < 100; ++n) {
		d1 = n % 10;
		d2 = (n / 10) % 10;
		cnt[n][0] = pattern[d1][0];
		cnt[n][1] = pattern[d1][1];
		cnt[n][2] = pattern[d1][2] + pattern[d2][0];
		cnt[n][3] = pattern[d2][1];
		cnt[n][4] = pattern[d2][2];
	}
	for (i = 0; i < 4; ++i) cnt[100][i] = 0;
	cnt[100][4] = 1;

	for (n = 2; n < 101; ++n)
	for (i = 0; i < 5; ++i)
		cnt[n][i] += cnt[n - 1][i];

	while (scanf("%d", &n) != EOF && n > 0) {
		printf("%d:", n);
		for (i = 0; i < 4; ++i)
			printf(" %d %c,", cnt[n][i], sym[i]);
		printf(" %d %c\n", cnt[n][4], sym[4]);
	}

	return 0;
}
