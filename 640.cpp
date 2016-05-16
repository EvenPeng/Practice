#include <cstdio>

using namespace std;

int main (void) {
	bool check[1000001];
	int n, sum, i;

	printf("1\n3\n5\n7\n9\n20\n31\n42\n53\n64\n75\n86\n97\n");

	for (i = 100; i < 1000001; ++i) check[i] = true;
	for (i = 82; i < 1000001; ++i) {
		n = i;
		sum = i;
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
		if (sum < 1000001) check[sum] = false;
	}

	for (i = 100; i < 1000001; ++i) 
		if (check[i]) printf("%d\n", i);

	return 0;
}
