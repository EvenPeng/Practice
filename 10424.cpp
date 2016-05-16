#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[]){
	char name1[26], name2[26];
	int sum1, sum2, len, tmp;
	double result;

	while(scanf("%[^\n] %[^\n]", name1, name2) == 2){
		len = strlen(name1);
		sum1 = 0;
		for (int i = 0; i < len; ++i){
			if(('a' <= name1[i] && name1[i] <= 'z'))
				sum1 += (int)(name1[i] - 'a') + 1;
			else if('A' <= name1[i] && name1[i] <= 'Z')
				sum1 += (int)(name1[i] - 'A') + 1;
		}
		len = strlen(name2);
		sum2 = 0;
		for (int i = 0; i < len; ++i){
			if(('a' <= name2[i] && name2[i] <= 'z'))
				sum2 += (int)(name2[i] - 'a') + 1;
			else if('A' <= name2[i] && name2[i] <= 'Z')
				sum2 += (int)(name2[i] - 'A') + 1;
		}
		while(sum1 > 9){
			tmp = sum1;
			sum1 = 0;
			while(tmp > 0){
				sum1 += tmp % 10;
				tmp /= 10;
			}
		}
		while(sum2 > 9){
			tmp = sum2;
			sum2 = 0;
			while(tmp > 0){
				sum2 += tmp % 10;
				tmp /= 10;
			}
		}
		if(sum1 > sum2) result = 100.0 * sum2 / sum1;
		else result = 100.0 * sum1 / sum2;

		printf("%.2f %%\n", result);
		getchar();
	}

	return 0;
}