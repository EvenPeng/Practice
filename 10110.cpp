#include <iostream>
#include <cmath>

using namespace std;

int main (void) {
	long n, s;

	while (cin >> n && n > 0) {
		s = sqrt(n);
		if (s * s == n) cout << "yes" << endl;
		else cout << "no" << endl;
	}

	return 0;
}
