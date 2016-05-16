#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	int i, index, cnt[2][26];
	char arr[10000];

	while(gets(arr) != NULL) {
		for (i = 0; i < 26; ++i) cnt[0][i] = 0;
		for (i = 0; i < strlen(arr); ++i) {
			index = (int)(arr[i] - 'a');
			if (-1 < index && index < 26)
				cnt[0][index] ++;
		}
		gets(arr);
		for (i = 0; i < 26; ++i) cnt[1][i] = 0;
		for (i = 0; i < strlen(arr); ++i) {
			index = (int)(arr[i] - 'a');
			if (-1 < index && index < 26)
				cnt[1][index] ++;
		}
		for (i = 0; i < 26; ++i)
			cnt[0][i] = cnt[0][i] < cnt[1][i]? cnt[0][i]: cnt[1][i];
		for (index = 0; index < 26; ++index)
		for (i = 0; i < cnt[0][index]; ++i) printf("%c", (char)(index + 'a'));
		printf("\n");
	}	

	return 0;
}
