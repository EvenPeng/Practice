#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	char in[1000], str[100000];
	int times, index, i, j, len, head;

	scanf("%d\n", &times);
	index = 0;
	while (times--) {
		scanf("%s", in);
		len = 0;
		j = 0;
		for (i = 0; i < strlen(in); ++i) {
			if ('A' <= in[i] && in[i] <= 'Z') {
				while (j --) {
					str[len++] = in[head];
				}
				head = i;
				j = 0;
			} else {
				j *= 10;
				j += in[i] - '0';
			}
		}
		while (j --) {
			str[len++] = in[head];
		}
		head = i;
		j = 0;
		str[len] = '\0';
		printf("Case %d: %s\n", ++index, str);
	}

	return 0;
}
