#include <cstdio>
#include <cstring>

using namespace std;

int lenP, prime[50], square[50];

bool isPrime (int x) {
	int i;
	
	if (x < 2) return false;

	for (i = 0; square[i] <= x; ++i)
	if (x % prime[i] == 0) return false;

	return true;
}

int main (void) {
	bool flag;
	char str[2005];
	int i, j, index, times, cnt[130];

	lenP = 2;
	prime[0] = 2;
	prime[1] = 3;
	square[0] = 4;
	square[1] = 9;

	i = 3;
	while (square[lenP - 1] < 2001) {
		i += 2;
		flag = true;
		for (j = 0; flag && square[j] < i; ++j)
		flag &= i % prime[j] != 0;
		if (flag) {
			prime[lenP] = i;
			square[lenP++] = i * i;
		}
	}

	index = 0;
	scanf("%d", &times);

	while (times-- > 0) {
		scanf("%s", str);
		memset(cnt, 0, sizeof(int) * 130);
		for (i = 0; str[i] != '\0'; ++i) cnt[str[i]] ++;
		printf("Case %d: ", ++index);
		flag = false;
		for (i = '0'; i <= '9'; ++i) if (isPrime(cnt[i])) {
			flag = true;
			printf("%c", i);
		}
		for (i = 'A'; i <= 'Z'; ++i) if (isPrime(cnt[i])) {
			flag = true;
			printf("%c", i);
		}
		for (i = 'a'; i <= 'z'; ++i) if (isPrime(cnt[i])) {
			flag = true;
			printf("%c", i);
		}
		if (!flag) printf("empty\n");
		else printf("\n");
	}

	return 0;
}
