#include <cstdio>

using namespace std;

int main (void) {
	bool flag;
	int Z, I, M, L, index;
	int i, len, list[100000];

	index = 0;
	while (true) {
		scanf("%d %d %d %d", &Z, &I, &M, &L);
		if (Z == 0 && I == 0 && M == 0 && L == 0) break;

		len = 1;
		list[0] = L;
		flag = true;
		while (flag) {
			list[len] = (Z * list[len - 1] + I) % M;
			for (i = 0; flag && i < len; ++i)
			flag &= list[i] != list[len];
			len ++;
		}

		printf("Case %d: %d\n", ++index, len - i);
	}

	return 0;
}
