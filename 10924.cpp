#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

bool check (int sum) {
	int i, bound;

	if (sum > 2 && sum % 2 == 0) return false;

	bound = (int)(sqrt((double) sum) + 0.5);
	for (i = 3; i <= bound; i += 2)
		if (sum % i == 0) return false;

	return true;
}

int main (void) {
	char word[21];
	int i, sum;

	while (scanf("%s", word) != EOF) {
		sum = 0;
		for (i = 0; i < strlen(word); ++i)
		if ('a' <= word[i] && word[i] <= 'z') sum += word[i] - 'a' + 1;
		else if ('A' <= word[i] && word[i] <= 'Z') sum += word[i] - 'A' + 27;

		if (check(sum)) printf("It is a prime word.\n");
		else printf("It is not a prime word.\n");
	}

	return 0;
}
