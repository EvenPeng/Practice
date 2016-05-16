#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[]){
	int list[1000005], count, index, min, max, cases;
	char sequence[1000005];

	cases = 1;

	while(scanf("%s", sequence) == 1){
		count = strlen(sequence);

		index = 0;
		list[0] = index;

		for (int i = 1; i < count; ++i){		
			if(sequence[i-1] != sequence[i])
				index ++;

			list[i] = index;
		}

		scanf("%d", &count);

		printf("Case %d:\n", cases++);

		for (int i = 0; i < count; ++i){
			scanf("%d %d", &min, &max);

			if(list[min] == list[max])
				printf("Yes\n");
			else
				printf("No\n");
		}
	}

	return 0;
}