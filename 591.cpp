#include <iostream>

using namespace std;

int main (void) {
	int i, len, cases, arr[50], moves, avg;

	cases = 0;

	while (cin >> len && len > 0) {
		moves = 0;
		avg = 0;

		for (i = 0; i < len; ++i) {
			cin >> arr[i];
			avg += arr[i];
		}

		avg /= len;

		for (i = 0; i < len; ++i)
			if (arr[i] > avg) moves += arr[i] - avg;

		cout << "Set #" << ++cases << endl;
		cout << "The minimum number of moves is " << moves << "." << endl << endl;
	}

	return 0;
}
