#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	char comm[10];
	int n, list[6], tmpI;
	int init[6] = {2,3,1,4,5,6};

	while (true) {
		scanf("%d", &n);
		if (!n) break;

		memcpy(list, init, sizeof(int) * 6);
		while (n--) {
			scanf("%s", comm);
			if (comm[0] == 'n') {
				tmpI = list[0];
				list[0] = list[2];
				list[2] = list[4];
				list[4] = list[5];
				list[5] = tmpI;
			} else if (comm[0] == 'w') {
				tmpI = list[1];
				list[1] = list[2];
				list[2] = list[3];
				list[3] = list[5];
				list[5] = tmpI;
			} else if (comm[0] == 's') {
				tmpI = list[5];
				list[5] = list[4];
				list[4] = list[2];
				list[2] = list[0];
				list[0] = tmpI;
			} else {
				tmpI = list[5];
				list[5] = list[3];
				list[3] = list[2];
				list[2] = list[1];
				list[1] = tmpI;
			}
		}

		printf("%d\n", list[2]);
	}

	return 0;
}
