#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	int A, B, aX, aY, bX, bY, t;

	while (scanf("%d %d", &A, &B) != EOF) {
		aX = 1;
		aY = 0;
		bX = 0;
		bY = 1;

		while (A && B) {
			if (A > B) {
				t = A / B;
				aX -= bX * t;
				aY -= bY * t;
				A %= B;
			} else if (B > A) {
				t = B / A;
				bX -= aX * t;
				bY -= aY * t;
				B %= A;
			} else break;
		}

		if (A > B ) printf("%d %d %d\n", aX, aY, A);
		else printf("%d %d %d\n", bX, bY, B);
	}

	return 0;
}
