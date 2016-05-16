#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	int times, map[130], i, sum, tmpI, base;
	char A[10], B[10], op[10];

	memset(map, 0, sizeof(int) * 130);
	for (i = 0; i < 10; ++i) map[i + '0'] = i;
	map['A'] = 10;
	map['B'] = 11;
	map['C'] = 12;
	map['D'] = 13;
	map['E'] = 14;
	map['F'] = 15;

	scanf("%d", &times);

	while (times-- > 0) {
		scanf("%s %s %s", A, op, B);
		sum = 0;
		for (i = 0; i < strlen(A); ++i) {
			sum *= 16;
			sum += map[A[i]];
		}
		tmpI = 0;
		for (i = 0; i < strlen(B); ++i) {
			tmpI *= 16;
			tmpI += map[B[i]];
		}
		base = 1 << 11;
		printf("0");
		for (i = 0; i < 12; ++i) {
			if (sum & base) printf("1");
			else printf("0");
			base >>= 1;
		}
		printf(" %c ", op[0]);
		base = 1 << 11;
		printf("0");
		for (i = 0; i < 12; ++i) {
			if (tmpI & base) printf("1");
			else printf("0");
			base >>= 1;
		}
		if (op[0] == '+') sum += tmpI;
		else sum -= tmpI;
		printf(" = %d\n", sum);
	}

	return 0;
}
