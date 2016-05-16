#include <cstdio>

using namespace std;

int cnt[1000000];

int val (int x) {
	int tmpI, sum;

	if (cnt[x] < 0) {
		sum = 0;
		tmpI = x;

		while (tmpI > 1) {
			if (tmpI % 2) {
				sum += 2;
				tmpI += (tmpI + 1) / 2;
			} else {
				sum ++;
				tmpI /= 2;
			}
			if (tmpI < 1000000) {
				sum += val(tmpI);
				tmpI = 1;
			}
		}

		cnt[x] = sum;
		return sum;
	} else
		return cnt[x];	
}

int main (void) {
	int oL, oR, L, R, max, curr, i;
	
	cnt[1] = 1;
	cnt[2] = 2;
	for (i = 3; i < 1000000; ++i) cnt[i] = -1;

	while (scanf("%d %d", &oL, &oR) != EOF) {
		max = 0;
		if (oL > oR) {
			L = oR;
			R = oL;
		} else {
			L = oL;
			R = oR;
		}
		for (i = L; i <= R; ++i) {
			curr = val(i);
			if (max < curr) max = curr;
		}
		printf("%d %d %d\n", oL, oR, max);
	}

	return 0;
}
