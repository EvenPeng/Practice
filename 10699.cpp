#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int main (void) {
	bool flag;
	int lenP, prime[1000], i, j, tmpI, bound, cnt;

	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	lenP = 3;
	for (i = 7; i < 1000; i += 2) {
		bound = (int)sqrt((double) i);
		flag = true;
		for (j = 0; flag && prime[j] <= bound; ++j)
			flag &= (i % prime[j] > 0);
		if (flag) prime[lenP++] = i;
	}

	while (true) {
		scanf("%d", &i);
		if (i == 0) break;
		else if (i == 1) {
			printf("1 : 0\n");
			continue;
		}

		bound = (int)sqrt((double) i);
		j = 0;
		cnt = 0;
		tmpI = i;

		while (prime[j] <= bound) {
			if (tmpI % prime[j] == 0) {
				cnt ++;
				while (tmpI % prime[j] == 0) tmpI /= prime[j];
			}
			++j;
			if (tmpI < 2 || j == lenP) break;
		}
		if (tmpI > 1) cnt ++;

		printf("%d : %d\n", i, cnt);
	}

	return 0;
}
