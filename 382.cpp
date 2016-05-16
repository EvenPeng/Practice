#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int check (int num) {
	if (num == 1) return 0;

	int sum = 1;
	int dividor = 1;
	int bound = sqrt(num);

	while (++dividor <= bound) {
		if (num % dividor == 0)
			sum += dividor + num / dividor;
	}

	if (sum < num) return 0;
	else if (sum == num) return 1;
	else return 2;
}

int main (int argc, char *argv[]) {
	int num;

	cout << "PERFECTION OUTPUT" << endl;

	while (true) {
		cin >> num;
		if (num == 0) break;

		printf("%5d  ", num);

		switch (check(num)) {
		case 0: printf("DEFICIENT\n"); break;
		case 1: printf("PERFECT\n"); break;
		default : printf("ABUNDANT\n");
		}
	}

	cout << "END OF OUTPUT" << endl;

	return 0;
}
