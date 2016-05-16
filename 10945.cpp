#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	bool flag;
	char in[10000];
	int len, i, j, map[130];

	memset(map, 0, sizeof(int) * 130);
	for (i = 0; i < 26; ++i) {
		map[i + 'A'] = i + 'a';
		map[i + 'a'] = i + 'a';
	}

	while (true) {
		gets(in);
		if (strcmp(in, "DONE") == 0) break;
		i = 0;
		j = strlen(in) - 1;
		flag = true;
		while (flag) {
			while (map[in[i]] == 0) ++i;
			while (map[in[j]] == 0) --j;
			if (i >= j) break;
			flag &= map[in[i++]] == map[in[j--]];
		}

		if (flag) printf("You won't be eaten!\n");
		else printf("Uh oh..\n");
	}

	return 0;
}
