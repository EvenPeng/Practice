#include <cstdio>
#include <cstring>

using namespace std;

int n, m, k, len[21], pos[21][2];
char grid[53][53], word[21][52];

bool check (int index, int x, int y) {
	bool flag;
	int i;

	if (y - len[index] + 1 > 0 ) {
		flag = true;
		for (i = 0; flag && i < len[index]; ++i)
		flag &= grid[x][y - i] == word[index][i];
		if (flag) return true;

		if (x - len[index] + 1 > 0) {
			flag = true;
			for (i = 0; flag && i < len[index]; ++i)
			flag &= grid[x - i][y - i] == word[index][i];
			if (flag) return true;
		}
	}

	if (len[index] + y - 1 <= m) {
		flag = true;
		for (i = 0; flag && i < len[index]; ++i)
		flag &= grid[x][y + i] == word[index][i];
		if (flag) return true;

		if (x - len[index] + 1 > 0) {
			flag = true;
			for (i = 0; flag && i < len[index]; ++i)
			flag &= grid[x - i][y + i] == word[index][i];
			if (flag) return true;
		}
	}

	if (x - len[index] + 1 > 0) {
		flag = true;
		for (i = 0; flag && i < len[index]; ++i)
		flag &= grid[x - i][y] == word[index][i];
		if (flag) return true;
	}

	if (len[index] + x - 1 <= n) {
		flag = true;
		for (i = 0; flag && i < len[index]; ++i)
		flag &= grid[x + i][y] == word[index][i];
		if (flag) return true;

		if (len[index] + y - 1 <= m) {
			flag = true;
			for (i = 0; flag && i < len[index]; ++i)
			flag &= grid[x + i][y + i] == word[index][i];
			if (flag) return true;
		}

		if (y - len[index] + 1 > 0) {
			flag = true;
			for (i = 0; flag && i < len[index]; ++i)
			flag &= grid[x + i][y - i] == word[index][i];
			if (flag) return true;
		}
	}

	return false;
}

int main (void) {
	char diff = 'A' - 'a';
	int times, i, j, index;

	scanf("%d", &times);

	while (times-- > 0) {
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; ++i) {
			scanf("%s", &grid[i][1]);
			for (j = 1; j <= m; ++j)
			if ('A' <= grid[i][j] && grid[i][j] <= 'Z')
				grid[i][j] -= diff;
		}

		scanf("%d", &k);
		for (index = 0; index < k; ++index) {
			scanf("%s", &word[index][0]);
			len[index] = strlen(word[index]);
			pos[index][0] = 0;
			for (j = 0; j < len[index]; ++j)
			if ('A' <= word[index][j] && word[index][j] <= 'Z')
				word[index][j] -= diff;
		}

		for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
		for (index = 0; index < k; ++index)
		if (pos[index][0] == 0 && check(index, i, j)) {
			pos[index][0] = i;
			pos[index][1] = j;
		}

		for (index = 0; index < k; ++index)
		printf("%d %d\n", pos[index][0], pos[index][1]);

		if (times > 0) printf("\n");
	}

	return 0;
}
