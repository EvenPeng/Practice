#include <cstdio>
#include <cstring>

using namespace std;

bool check[1001];
int n, len, ans[1001], list[1001], cnt[10], tcnt[10];;

int main (void) {
	bool flag;
	int i, index, strong, weak;

	index = 0;
	while (true) {
		scanf("%d", &n);
		if (!n) break;

		memset(cnt, 0, sizeof(int) * 10);
		for (i = 0; i < n; ++i) {
			scanf("%d", ans + i);
			cnt[ans[i]] ++;
		}
		printf("Game %d:\n", ++index);
		flag = true;
		while (flag) {
			memset(check, true, sizeof(bool) * n);
			memcpy(tcnt, cnt, sizeof(int) * 10);
			strong = 0;
			weak = 0;
			for (i = 0; i < n; ++i) {
				scanf("%d", list + i);
				flag &= list[i] > 0;
				if (list[i] == ans[i]) {
					check[i] = false;
					tcnt[list[i]] --;
					strong ++;
				}
			}
			if (flag) {
				for (i = 0; i < n; ++i)
				if (check[i] && tcnt[list[i]] > 0) {
					tcnt[list[i]] --;
					weak ++;
				}
				printf("    (%d,%d)\n", strong, weak);
			}
		}
	}

	return 0;
}
