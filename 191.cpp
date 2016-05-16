#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	bool flag;
	int times;
	double lx1, ly1, lx2, ly2, rx1, ry1, rx2, ry2, m, b;
	double vx1, vy1, vx2, vy2;

	scanf("%d", &times);

	while (times--) {
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &lx1, &ly1, &lx2, &ly2, &rx1, &ry1, &rx2, &ry2);
		if (rx1 > rx2) {
			vx1 = rx1;
			rx1 = rx2;
			rx2 = vx1;
		}
		if (ry1 > ry2) {
			vy1 = ry1;
			ry1 = ry2;
			ry2 = vy1;
		}
		if (lx1 > lx2) {
			vx1 = lx2;
			vx2 = lx1;
		} else {
			vx1 = lx1;
			vx2 = lx2;
		}
		if (ly1 > ly2) {
			vy1 = ly2;
			vy2 = ly1;
		} else {
			vy1 = ly1;
			vy2 = ly2;
		}
		flag = (vx1 <= rx2 && vy1 <= ry2 ) && (vx2 >= rx1 && vy2 >= ry1);
		if (flag) {
			flag = lx1 == lx2;
			if (!flag) {
				m = (ly2 - ly1) / (lx2 - lx1);
				b = ly1 - m * lx1;
				flag |= (m * rx1 - ry1 + b) * (m * rx2 - ry2 + b) <= 0;
				if (!flag) flag |= (m * rx1 - ry2 + b) * (m * rx2 - ry1 + b) <= 0;
			}
		}

		if (flag) printf("T\n");
		else printf("F\n");
	}

	return 0;
}
