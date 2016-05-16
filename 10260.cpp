#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	char sen[21];
	int i, cur, pre;

	while (scanf("%s", sen) != EOF) {
		pre = 0;
		for (i = 0; i < strlen(sen); ++i) {
			switch (sen[i]) {
			case 'B':
			case 'F':
			case 'P':
			case 'V':
				cur = 1;
				break;
			case 'C':
			case 'G':
			case 'J':
			case 'K':
			case 'Q':
			case 'S':
			case 'X':
			case 'Z':
				cur = 2;
				break;
			case 'D':
			case 'T':
				cur = 3;
				break;
			case 'L':
				cur = 4;
				break;
			case 'M':
			case 'N':
				cur = 5;
				break;
			case 'R':
				cur = 6;
				break;
			default:
				cur = 0;
			}

			if (cur > 0 && cur != pre) printf("%d", cur);
			pre = cur;
		}
		printf("\n");
	}

	return 0;
}
