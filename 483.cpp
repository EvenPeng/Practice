#include <iostream>
#include <string>

using namespace std;

int main (void) {
	string str;
	int i, head, tail;

	while (getline(cin, str)) {
		for (head = -1, tail = 0; tail < str.size(); ++tail) {
			if (str[tail] == ' ') {
				for (i = tail - 1; i > head; --i) cout << str[i];
				head = tail;
				cout << ' ';
			} else if (tail == str.size() - 1)	
				for (i = tail; i > head; --i) cout << str[i];
		}
		cout << endl;
	}

	return 0;
}
