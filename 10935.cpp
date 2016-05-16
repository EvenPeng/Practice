#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	int queue[50], rear, len, i;

	while (true) {
		scanf("%d", &len);
		if (len < 1) break;
		for (i = 0; i < len; ++i) queue[i] = i + 1;
		rear = 0;
		printf("Discarded cards:");
		while (len > 1) {
			printf(" %d", queue[rear]);
			queue[(rear + len) % 50] = queue[(rear + 1) % 50];
			rear = (rear + 2) % 50;
			if (-- len > 1) printf(",");
			else break;
		}
		printf("\n");
		printf("Remaining card: %d\n", queue[rear]);
	}

	return 0;
}
