#include <cstdio>
#include <cmath>

using namespace std;

int main (void) {
	int d2[10], d4[100], d6[1000], d8[10000];
	int base, len2, len4, len6, len8, i, j, n;

	len2 = 0;
	base = 10;
	for (i = 0; i < base; ++i)
	for (j = 0; i + j < base; ++j)
	if (pow(i + j, 2) == (i * base + j))
		d2[len2 ++] = (i * base +j);
	len4 = 0;
	base = 100;
	for (i = 0; i < base; ++i)
	for (j = 0; i + j < base; ++j)
	if (pow(i + j, 2) == (i * base + j))
		d4[len4 ++] = (i * base +j);
	len6 = 0;
	base = 1000;
	for (i = 0; i < base; ++i)
	for (j = 0; i + j < base; ++j)
	if (pow(i + j, 2) == (i * base + j))
		d6[len6 ++] = (i * base +j);
	len8 = 0;
	base = 10000;
	for (i = 0; i < base; ++i)
	for (j = 0; i + j < base; ++j)
	if (pow(i + j, 2) == (i * base + j))
		d8[len8 ++] = (i * base +j);

	while (scanf("%d", &n) != EOF)
	switch (n) {
	case 2:
		for (i = 0; i < len2; ++i) printf("%02d\n", d2[i]);
		break;
	case 4:
		for (i = 0; i < len4; ++i) printf("%04d\n", d4[i]);
		break;
	case 6:
		for (i = 0; i < len6; ++i) printf("%06d\n", d6[i]);
		break;
	case 8:
		for (i = 0; i < len8; ++i) printf("%08d\n", d8[i]);
		break;
	}

	return 0;
}
