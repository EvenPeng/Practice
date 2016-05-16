#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	bool uflag, pflag, iflag, under, minus;
	char str[100000];
	int times, index, i, j, len;
	double U, P, I, point;

	scanf("%d\n", &times);

	index = 0;
	while (times--) {
		uflag = false;
		pflag = false;
		iflag = false;
		gets(str);

		len = strlen(str);
		for (i = 0; i < len; ++i)
		if (str[i] == '=') {
			point = 1;
			under = false;
			minus = false;
			if (str[i - 1] == 'U') {
				uflag = true;
				U = 0;
				for (j = i + 1; str[j] != 'V'; ++j)
				if (str[j] == 'k') point /= 1000;
				else if (str[j] == 'M') point /= 1000000;
				else if (str[j] == 'm') point /= 0.001;
				else if (str[j] == '.') under = true;
				else if (str[j] == '-') minus = true;
				else {
					U = U * 10 + str[j] - '0';
					if (under) point *= 10;
				}
				i = j;
				U /= point;
				if (minus) U *= -1;
			} else if (str[i - 1] == 'I') {
				iflag = true;
				I = 0;
				for (j = i + 1; str[j] != 'A'; ++j)
				if (str[j] == 'm') point /= 0.001;
				else if (str[j] == 'M') point /= 1000000;
				else if (str[j] == 'k') point /= 1000;
				else if (str[j] == '.') under = true;
				else if (str[j] == '-') minus = true;
				else {
					I = I * 10 + str[j] - '0';
					if (under) point *= 10;
				}
				i = j;
				I /= point;
				if (minus) I *= -1;
			} else {
				pflag = true;
				P = 0;
				for (j = i + 1; str[j] != 'W'; ++j)
				if (str[j] == 'M') point /= 1000000;
				else if (str[j] == 'm') point /= 0.001;
				else if (str[j] == 'k') point /= 1000;
				else if (str[j] == '.') under = true;
				else if (str[j] == '-') minus = true;
				else {
					P = P * 10 + str[j] - '0';
					if (under) point *= 10;
				}
				i = j;
				P /= point;
				if (minus) P *= -1;
			}
		}

		printf("Problem #%d\n", ++index);
		if (!uflag) printf("U=%.2lfV\n\n", P / I);
		else if (!pflag) printf("P=%.2lfW\n\n", U * I);
		else printf("I=%.2lfA\n\n", P / U);
	}

	return 0;
}
