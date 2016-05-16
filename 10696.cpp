#include <iostream>
#include <cstdlib>

using namespace std;

int main (void) {
	int num;

	while(true) {
		scanf("%d", &num);
		if (!num) break;
		if(num < 101) printf("f91(%d) = 91\n", num);
		else printf("f91(%d) = %d\n", num, num - 10);
	}
	
	return 0;
}
