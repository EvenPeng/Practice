#include <cstdio>

using namespace std;

int main (void) {
	int i, min, index[4], value[4], mul[4], curr, len, list[5843];
	
	len = 2;
	list[1] = 1;
	mul[0] = 2;
	mul[1] = 3;
	mul[2] = 5;
	mul[3] = 7;
	for (i = 0; i < 4; ++i) {
		index[i] = 1;
		value[i] = mul[i];
	}

	while (len < 5843) {
		min = value[0];
		for (i =1; i < 4; ++i)
		if (value[i] < min) min = value[i];
		list[len++] = min;
		for (i = 0; i < 4; ++i) if (value[i] == min) {
			index[i] ++;
			value[i] = list[index[i]] * mul[i];
		}
	}

	while (true) {
		scanf("%d", &curr);
		if (curr < 1) break;
		if ((curr % 100) / 10 != 1 && curr % 10 == 1) printf("The %dst humble number is %d.\n", curr, list[curr]);
		else if ((curr % 100) / 10 != 1 && curr % 10 == 2) printf("The %dnd humble number is %d.\n", curr, list[curr]);
		else if ((curr % 100) / 10 != 1 && curr % 10 == 3) printf("The %drd humble number is %d.\n", curr, list[curr]);
		else printf("The %dth humble number is %d.\n", curr, list[curr]);
	}

	return 0;
}
