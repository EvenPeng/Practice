#include <iostream>
#include <string>

using namespace std;

int main (void) {
	string str;
	int i, num;

	while (cin >> str) {
		if (str.size() == 1 && str[0] == '0') break;
		
		num = 0;

		for (i = 0; i < str.size(); ++i) {
			num += (int)(str[i] - '0');
			num %= 11;
			num *= 10;
		}

		if (num % 11 == 0)
			cout << str << " is a multiple of 11." << endl;
		else
			cout << str << " is not a multiple of 11." << endl;
	}

	return 0;
}
