#include <cstdio>

using namespace std;

int main(void){
	int times, arr[10], i, con;
	bool flag;

	scanf("%d", &times);
	printf("Lumberjacks:\n");

	while (times--) {
		for (i = 0; i < 10; ++i) scanf("%d", arr + i);

		con = 0;
		for (i = 0; !con && i < 9; ++i) {
			if (arr[i] > arr[i + 1]) con = 1;
			else if (arr[i] < arr[i + 1]) con = -1;
		}

		flag = true;
		if (con > 0) {
			for (; i < 9 && flag; ++i) if (arr[i] < arr[i + 1]) flag = false;
		} else if(con < 0) {
			for (; i < 9 && flag; ++i) if (arr[i] > arr[i + 1]) flag = false;
		}

		if(flag) printf("Ordered\n");
		else printf("Unordered\n");
	}

	return 0;
}
