#include <cstdio>
#include <cmath>

using namespace std;

int main (void) {
	int left, right;

	while (scanf("%d %d", &left, &right) != EOF) {
		if (left == 0 && right == 0) break;
		
		left = (int)sqrt((double)left - 1);
		right = (int)sqrt((double)right);

		printf("%d\n", right - left);
	}

	return 0;
}
