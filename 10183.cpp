#include <cstdio>
#include <cstring>
#include <cmath>

#define BASE 1000000000000

using namespace std;

struct fab {
	int len;
	long digit[10];
};

static inline int cmp (fab *x, fab *y) {
	int i;

	if (x->len == y->len) {
		for (i = x->len - 1; i > -1; --i)
		if (x->digit[i] > y->digit[i]) return 1;
		else if (x->digit[i] < y->digit[i]) return -1;
	} else return x->len - y->len;

	return 0;
}

int main (void) {
	char bn[110], en[110];
	fab list[500], bound, beg, end;
	int len, begI, endI, i, j, con, map[128];

	for (i = 0; i < 10; ++i) map[i + '0'] = i;
	memset(list[1].digit, 0, sizeof(long) * 10);
	list[1].len = 1;
	list[1].digit[0] = 1;
	memset(list[2].digit, 0, sizeof(long) * 10);
	list[2].len = 1;
	list[2].digit[0] = 1;
	memset(bound.digit, 0, sizeof(long) * 10);
	bound.len = 9;
	bound.digit[8] = 10000;

	len = 3;
	while (true) {
		memcpy(list + len, list + len - 1, sizeof(fab));
		
		for (i = 0; list[len].digit[i]; ++i) {
			list[len].digit[i] += list[len - 2].digit[i];
			if (list[len].digit[i] >= BASE) {
				list[len].digit[i + 1] ++;
				list[len].digit[i] -= BASE;
			}
		}
		list[len].len = i;

		if (cmp(list + len, &bound) >= 0) break;
		else len ++;
	}
	len ++;

	while (true) {
		scanf("%s %s", bn, en);
		if (bn[0] == '0' && en[0] == '0' && strlen(bn) == 1 && strlen(en) == 1) break;
		memset(beg.digit, 0, sizeof(long) * 10);
		memset(end.digit, 0, sizeof(long) * 10);
		begI = strlen(bn);
		beg.len = --begI / 12 + 1;
		for (i = 0; i <= begI; ++i)
			beg.digit[(begI - i) / 12] += (long)map[bn[i]] * (long)pow(10, (begI - i) % 12);
		endI = strlen(en);
		end.len = --endI / 12 + 1;
		for (i = 0; i <= endI; ++i)
			end.digit[(endI - i) / 12] += (long)map[en[i]] * (long)pow(10, (endI - i) % 12);

		i = 1;
		j = len;
		while (j - i > 1) {
			begI = (i + j) / 2;
			con = cmp(&beg, list + begI);
			if (con < 0) j = begI;
			else if (con > 0) i = begI;
			else break;
		}
		i = 1;
		j = len;
		while (j - i > 1) {
			endI = (i + j) / 2;
			con = cmp(&end, list + endI);
			if (con < 0) j = endI;
			else if (con > 0) i = endI;
			else break;
		}
		if (cmp(&beg, list + begI) > 0) begI ++;
		if (cmp(&end, list + endI) < 0) endI --;
		if (begI <= endI) printf("%d\n", endI - begI + 1);
		else printf("0\n");
	}

	return 0;
}
