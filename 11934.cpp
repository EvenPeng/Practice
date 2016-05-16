#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	int a, b, c, d, l, i;
	int sq[1000], cnt;
	
	for (i = 0; i < 1000; ++i) sq[i] = i * i;
	while (true) {
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &l);
		if (!a && !b && !c && !d && !l) break;
		cnt = 0;
		for (i = 0; i <= l; ++i)
		if (!((a * sq[i] + b * i + c) % d)) cnt ++;
		printf("%d\n", cnt);
	}

	return 0;
}
