#include <cstdio>
#include <cstring>

using namespace std;

bool table[6][6];
char seq[10];
int cnt, len;

void route (int x) {
	int i;

	for (i = 1; i < 6; ++i)
	if (table[x][i]) {
		table[x][i] = false;
		table[i][x] = false;
		seq[len++] = '0' + i;
		cnt --;

		if (cnt == 0) printf("%s\n", seq);
		else route(i);

		table[x][i] = true;
		table[i][x] = true;
		len --;
		cnt ++;
	}
}

int main (void) {
	int i;

	cnt = 8;
	memset(table, true, sizeof(char) * 36);

	for (i = 1; i < 6; ++i) table[i][i] = false;
	table[1][4] = false;
	table[2][4] = false;
	table[4][1] = false;
	table[4][2] = false;

	len = 1;
	seq[0] = '1';
	seq[8] = '\0';
	route(1);

	return 0;
}
