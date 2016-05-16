#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main (void) {
	double h, k, r, c, d, e;
	double Ax, Ay, Bx, By, Cx, Cy;
	
	while (scanf("%lf %lf %lf %lf %lf %lf", &Ax, &Ay, &Bx, &By, &Cx, &Cy) != EOF) {
		if (Ay == By) {
			h = (Ax + Bx) / 2;	
			k = ((Ax * Ax + Ay * Ay - Cx * Cx - Cy * Cy) / 2 - (Ax - Cx) * h) / (Ay - Cy);
		} else if (Ay == Cy) {
			h = (Ax + Cx) / 2;	
			k = ((Ax * Ax + Ay * Ay - Bx * Bx - By * By) / 2 - (Ax - Bx) * h) / (Ay - By);
		} else {
			h = ((Ax * Ax + Ay * Ay - Bx * Bx - By * By) / (Ay - By)
				- (Ax * Ax + Ay * Ay - Cx * Cx - Cy * Cy) / (Ay - Cy)) / 2
				/ ((Ax - Bx) / (Ay - By) - (Ax - Cx) / (Ay - Cy));
			k = ((Ax * Ax + Ay * Ay - Bx * Bx - By * By) / 2 - (Ax - Bx) * h) / (Ay - By);
		}
		r = sqrt(pow(Ax - h, 2) + pow(Ay - k, 2));

		if (h < 0) printf("(x + %.3lf)^2 + ", -(h));
		else if (h > 0)  printf("(x - %.3lf)^2 + ", h);
		else printf("x^2 + ");
		if (k < 0) printf("(y + %.3lf)^2 = %.3lf^2\nx^2 + y^2", -(k), r);
		else if (k > 0)  printf("(y - %.3lf)^2 = %.3lf^2\nx^2 + y^2", k, r);
		else printf("y^2 = %.3lf^2\nx^2 + y^2", r);
		if (h < 0) printf(" + %.3lfx", h * -2);
		else if (h > 0)  printf(" - %.3lfx", h * 2);
		if (k < 0) printf(" + %.3lfy", k * -2);
		else if (k > 0)  printf(" - %.3lfy", k * 2);
		e = h * h + k * k - r * r;
		if (e < 0) printf(" - %.3lf = 0\n\n", -(e));
		else if (e > 0)  printf(" + %.3lf = 0\n\n", e);
		else printf(" = 0\n\n");
	}

	return 0;
}
