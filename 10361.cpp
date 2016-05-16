#include <cstdio>
#include <cstring>

using namespace std;

int main (void) {
	char s1[105], s2[105], s3[105], s4[105], s5[105];
	int len1, len2, len3, len4, len5, i, times;

	scanf("%d\n", &times);

	while (times-- > 0) {
		gets(s1);
		len1 = strlen(s1);
		i = 0;
		while (s1[i] != '<') ++i;
		s1[i++] = '\0';
		len2 = 0;
		while (s1[i] != '>') s2[len2++] = s1[i++];
		s2[len2] = '\0';
		i ++;
		len3 = 0;
		while (s1[i] != '<') s3[len3++] = s1[i++];
		s3[len3] = '\0';
		i ++;
		len4 = 0;
		while (s1[i] != '>') s4[len4++] = s1[i++];
		s4[len4] = '\0';
		i ++;
		len5 = 0;
		while (i < len1) s5[len5++] = s1[i++];
		s5[len5] = '\0';
		printf("%s%s%s%s%s\n", s1, s2, s3, s4, s5);
		gets(s1);
		len1 = strlen(s1);
		i = 0;
		while (s1[i] != '.') ++i;
		s1[i++] = '\0';
		printf("%s%s%s%s%s\n", s1, s4, s3, s2, s5);
	}

	return 0;
}
