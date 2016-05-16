#include <cstdio>

using namespace std;

int gcd (int x, int y) {
	while (x > 0 && y > 0) {
		if (x > y) x %= y;
		else if (y > x) y %= x;
		else return x;
	}

	return x > y? x: y;
}

int cntDigit (int x) {
	int num, bound;
	num = 1;
	bound = 1;

	while (x / bound > 0) {
		num ++;
		bound *= 10;
	}

	return num - 1;
}

int main (void) {
	bool flag;
	int i, total, tmpI, cnt, index, comm, totalD, cntD, lenD;

	index = 0;
	while (true) {
		scanf("%d", &cnt);
		if (cnt < 1) break;

		printf("Case %d:\n", ++index);

		total = 0;
		for (i = 0; i < cnt; ++i) {
			scanf("%d", &tmpI);
			total += tmpI;
		}

		flag = total < 0;
		if (flag) total *= -1;

		if (total % cnt != 0) {
			comm = gcd(total, cnt);
			total /= comm;
			cnt /= comm;
			if (flag) lenD = 2;
			else lenD = 0;
			totalD = cntDigit(total % cnt);
			cntD = cntDigit(cnt);
			if (total > cnt) lenD += cntDigit(total / cnt);
			for (i = 0; i < lenD + cntD - totalD; ++i) printf(" ");
			printf("%d\n", total % cnt);
			if (flag) printf("- ");
			if (total > cnt) printf("%d", total / cnt);
			for (i = 0; i < cntD; ++i) printf("-");
			printf("\n");
			for (i = 0; i < lenD; ++i) printf(" ");
			printf("%d\n", cnt);
		} else {
			total /= cnt;
			if (flag) printf("- ");
			printf("%d\n", total);
		}
	}

	return 0;
}
