#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main (void) {
	int i, times, index, sum;
	int cnt[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
	char c[105];

	index = 0;
	scanf("%d", &times);
	getchar();

	while (times-- > 0) {
		sum = 0;
		gets(c);
		for (i = 0; i < strlen(c); ++i)
		if (c[i] != ' ') sum += cnt[c[i] - 'a'];
		else sum++;
		printf("Case #%d: %d\n", ++index, sum);
	}

	return 0;
}
