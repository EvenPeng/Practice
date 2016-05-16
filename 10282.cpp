#include <cstdio>
#include <cstring>

using namespace std;

struct word {
	char arr[15], label[20];
};

void sortL (word *list, int len) {
	int i = 0;
	int j = len - 1;
	word tmpS, pivot;

	if (len < 2) return;
	memcpy(&pivot, list + len / 2, sizeof(word));

	while (true) {
		while (strcmp(list[i].label, pivot.label) < 0) ++i;
		while (strcmp(list[j].label, pivot.label) > 0) --j;
		if (i >= j) break;

		memcpy(&tmpS, list + i, sizeof(word));
		memcpy(list + i, list + j, sizeof(word));
		memcpy(list + j, &tmpS, sizeof(word));
		i ++;
		j --;
	}

	sortL(list, i);
	sortL(list + i, len - i);
}

int main (void) {
	int head[26], cnt[26], map[130], len;
	word list[100001];
	int i, j, m, con;
	char tmpS[100];

	for (i = 0; i < 26; ++i) map['a' + i] = i;
	memset(head, 0, sizeof(int) * 26);
	memset(cnt, 0, sizeof(int) * 26);
	len = 0;

	while (gets(tmpS)) {
		con = sscanf(tmpS, "%s %s", list[len].arr, list[len].label);
		if (con != 2) break;
		cnt[map[list[len].label[0]]] ++;
		len ++;
	}
	
	head[0] = 0;
	for (i = 1; i < 26; ++i) head[i] = head[i - 1] + cnt[i - 1];
	sortL(list, len);

	while (gets(tmpS)) {
		sscanf(tmpS, "%s", list[len].arr);
		i = head[map[list[len].arr[0]]] - 1;
		j = cnt[map[list[len].arr[0]]] + i + 1;
		con = -1;
		while (j - i > 1) {
			m = (i + j) / 2;
			con = strcmp(list[len].arr, list[m].label);
			if (con < 0) j = m;
			else if (con > 0) i = m;
			else break;
		}

		if (con == 0) printf("%s\n", list[m].arr);
		else printf("eh\n");
	}

	return 0;
}
