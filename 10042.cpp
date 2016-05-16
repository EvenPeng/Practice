#include <cstdio>
#include <cmath>

using namespace std;

struct prime{
	int num, sum, square;
};

int len;
prime list[40000];

int accu (int x) {
	int sum = 0;

	while (x > 0) {
		sum += x % 10;
		x /= 10;
	}

	return sum;
}

void gen (int x) {
	bool flag;
	int i, j, tmpI;
	
	tmpI = list[len - 1].num;
	while (list[len - 1].square <= x) {
		tmpI += 2;
		flag = true;
		for (i = 0; flag && list[i].square <= tmpI; ++i) 
			flag &= tmpI % list[i].num != 0;
		if (flag) {
			list[len].num = tmpI;
			list[len].sum = accu(tmpI);
			list[len].square = tmpI * tmpI;
			len ++;
		}
	}
}

bool isSmith (int x) {
	int i, bound, sumO, sumP;

	if (list[len - 1].square <= x) gen(x);

	sumO = accu(x);
	sumP = 0;
	for (i = 0; list[i].square <= x; ++i)
	while (x % list[i].num == 0) {
		sumP += list[i].sum;
		if (sumP > sumO) return false;
		x /= list[i].num;
	}
	if (sumP > 0 && x > 1) sumP += accu(x);

	return sumO == sumP;
}

int main (void) {
	int times, n;

	len = 2;
	list[0].num = 2;
	list[0].sum = 2;
	list[0].square = 4;
	list[1].num = 3;
	list[1].sum = 3;
	list[1].square = 9;

	scanf("%d", &times);

	while (times-- > 0) {
		scanf("%d", &n);
		while (!isSmith(++n));
		printf("%d\n", n);
	}

	return 0;
}
