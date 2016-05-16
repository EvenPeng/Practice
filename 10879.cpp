#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	bool flag;
	int prime[10000], sq[10000], lenP;
	int i, j, times, index, A, B, C, D;

	lenP = 2;
	prime[0] = 2;
	sq[0] = 4;
	prime[1] = 3;
	sq[1] = 9;

	for (i = 5; i < 3163; i += 2) {
		flag = true;
		for (j = 0; sq[j] < i && flag; ++j) flag &= (i % prime[j] > 0);
		if (flag) {
			prime[lenP] = i;
			sq[lenP++] = i * i;
		}
	}

	scanf("%d", &times);
	index = 0;
	while (times--) {
		scanf("%d", &i);
		for (j = 0; sq[j] < i; ++j)
		if (i % prime[j] == 0) {
			A = prime[j];
			B = i / prime[j];
			if (B % prime[j] == 0) {
				C = A * A;
				D = B / A;
			} else {
				for (++j; sq[j] < i; ++j)
				if (i % prime[j] == 0) {
					C = prime[j];
					D = i / prime[j];
					break;
				}
			}
			break;
		}
		printf("Case #%d: %d = %d * %d = %d * %d\n", ++index, i, A, B, C, D);
	}

	return 0;
}
