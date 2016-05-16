#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	bool out, edge[52][52];
	char opt[110], cd, tran[5] = "NESW";
	int X, Y, i, x, y, d;
	int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

	scanf("%d %d", &X ,&Y);
	memset(edge, true, sizeof(bool) * 52 * 52);

	while (scanf("%d %d %c", &x, &y, &cd) != EOF) {
		scanf("%s", opt);
		switch (cd) {
		case 'N': d = 0; break;
		case 'E': d = 1; break;
		case 'S': d = 2; break;
		default: d = 3;
		}
		
		out = false;
		for (i = 0; i < strlen(opt); ++i) {
			if (opt[i] == 'R') d = (d + 1) % 4;
			else if (opt[i] == 'L') d = (d + 3) % 4;
			else {
				x += dir[d][0];
				y += dir[d][1];
				if (x < 0 || x > X || y < 0 || y > Y) {
					x -= dir[d][0];
					y -= dir[d][1];
					if (edge[x][y]) {
						edge[x][y] = false;
						out = true;
						break;
					}
				}
			}
		}

		if (out) printf("%d %d %c LOST\n", x, y, tran[d]);
		else printf("%d %d %c\n", x, y, tran[d]);
	}

	return 0;
}
