#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[]){
	int count, f, m, num;
	char tmp, seg[2];

	scanf("%d", &count);	

	for (int i = 0; i < count; ++i){
		f = 0;
		m = 0;
		num = 0;

		while(1){
			scanf("%s", seg);

			num ++;

			if(seg[0] == 'F') f++;
			else m++;

			if(seg[1] == 'F') f++;
			else m++;

			if(scanf("%c", &tmp) == EOF || tmp == '\n') break;
		}

		if(num > 1 && f == m) printf("LOOP\n");
		else printf("NO LOOP\n");
	}

	return 0;
}