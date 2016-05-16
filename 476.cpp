#include <cstdio>

using namespace std;

int main (void) {
	bool flag;
	char tmpChar;
	int lenR, lenP, i;
	double rect[10][4], point[2], tmpDouble;

	lenR = 0;
	while(scanf("%c ", &tmpChar) != EOF && tmpChar == 'r') {
		scanf("%lf %lf %lf %lf\n", &rect[lenR][0], &rect[lenR][1], &rect[lenR][2], &rect[lenR][3]);
		if (rect[lenR][2] < rect[lenR][0]) {
			tmpDouble = rect[lenR][2];
			rect[lenR][2] = rect[lenR][0];
			rect[lenR][0] = tmpDouble;
		}
		if (rect[lenR][3] < rect[lenR][1]) {
			tmpDouble = rect[lenR][3];
			rect[lenR][3] = rect[lenR][1];
			rect[lenR][1] = tmpDouble;
		}
		lenR ++;
	}

	lenP = 1;
	while(scanf("%lf %lf", &point[0], &point[1]) != EOF
			&& point[0] != 9999.9 && point[1] != 9999.9) {
		flag = true;
		for (i = 0; i < lenR; ++i)
			if (rect[i][0] < point[0] && point[0] < rect[i][2]
					&& rect[i][1] < point[1] && point[1] < rect[i][3]) {
				printf("Point %d is contained in figure %d\n", lenP, i + 1);
				flag = false;
			}
		if (flag) printf("Point %d is not contained in any figure\n", lenP);
		lenP ++;
	}
	return 0;
}
