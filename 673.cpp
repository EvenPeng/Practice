#include <iostream>
#include <cstring>

using namespace std;

int main (void) {
	bool flag;
	char stack[1000], arr[1000];
	int times, len, i;

	cin >> times;
	cin.getline(arr, 1000);

	while (times-- > 0) {
		cin.getline(arr, 1000);
		len = 0;
		flag = true;
		for (i = 0; i < strlen(arr); ++i) {
			if (arr[i] == '(' || arr[i] == '[') {
				stack[len++] = arr[i];
			} else if (len < 0) {
				flag = false;
				break;
			} else if (arr[i] == ')') {
				if (stack[--len] != '(') {
					flag = false;
					break;
				}
			} else {
				if (stack[--len] != '[') {
					flag = false;
					break;
				}
			}
		}

		if (len == 0 && flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}
