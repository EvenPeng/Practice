#include <iostream>
#include <cstdlib>

using namespace std;

int main (int argc, char *argv[]) {
	long cnt, ans, len, i, min, list[10000];

	cnt = 0;
	len = 1;
	list[0] = 1;

	while (true) {
		min = 0;
		for (i = 1; i < len; i++)
			if (list[i] < list[min])
				min = i;
		ans = list[min];

		if (++cnt == 1500) break;

		if (ans % 5 == 0) {
			list[min] = ans * 5;
		} else if (ans % 3 == 0) {
			list[min] = ans * 5;
			list[len++] = ans * 3;
		} else {
			list[min] = ans * 5;
			list[len++] = ans * 3;
			list[len++] = ans * 2;
		}
	}

	cout << "The 1500'th ugly number is " << ans << "." << endl;

	return 0;
}
