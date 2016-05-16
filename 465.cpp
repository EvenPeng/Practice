#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

using namespace std;

int main (void) {
	char num1[10000], num2[10000], op[10];
	long double I1, I2, R;

	while (scanf("%s %s %s", num1, op, num2) != EOF) {
		printf("%s %s %s", num1, op, num2);
		I1 = atof(num1);
		I2 = atof(num2);
		if (op[0] == '+') R = I1 + I2;
		else R = I1 * I2;
		if (I1 > INT_MAX) printf("\nfirst number too big");
		if (I2 > INT_MAX) printf("\nsecond number too big");
		if (R > INT_MAX) printf("\nresult too big");
		printf("\n");
	}

	return 0;
}
