#include <cstdio>
#include <cstring>

using namespace std;

char map[27][27];
int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

void cover (int x, int y) {
	int i;
	
	for (i = 0; i < 8; ++i)
	if (map[x + dir[i][0]][y + dir[i][1]] == '1') {
		map[x + dir[i][0]][y + dir[i][1]] = '0';
		cover(x + dir[i][0], y + dir[i][1]);
	}
}

int main (void) {
	int n, i, j, cnt, index;
	
	index = 0;
	memset(map[0], '0', sizeof(char) * 27);
	for (i = 0; i < 27; ++i) map[i][0] = '0';

	while (scanf("%d", &n) != EOF) {
		for (i = 1; i <= n; ++i) {
			scanf("%s", map[i] + 1);
			map[i][n + 1] = '0';
		}
		memset(map[n + 1], '0', sizeof(char) * 27);
		cnt = 0;

		for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
		if (map[i][j] == '1') {
			cnt ++;
			cover(i, j);
		}
		printf("Image number %d contains %d war eagles.\n", ++index, cnt);
	}

	return 0;
}
