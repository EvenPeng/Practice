#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	bool flag;
	int n, i, list[1001], head, tail, curr;

	while (true) {
		scanf("%d", &n);
		if (n < 1) break;

		while (true) {
			scanf("%d", list);
			if (list[0] == 0) {
				printf("\n");
				break;
			}
			for (i = 1; i < n; ++i) scanf("%d", list + i);
			for (i = 0; i < n; ++i)
			if (list[i] == n) {
				head = i - 1;
				tail = i + 1;
				break;
			}

			flag = true;
			curr = n - 1;
			while (curr > 0) {
				while (tail < n && list[tail] == curr) {
					tail ++;
					curr --;
				}
				if (curr == 0) break;
				while (head > -1 && list[head] != curr) list[--tail] = list[head--];
				if (head > -1) {
					curr --;
					head --;
				} else {
					flag = false;
					break;
				}
			}

			if (flag) printf("Yes\n");
			else printf("No\n");
		}
	}

	return 0;
}
