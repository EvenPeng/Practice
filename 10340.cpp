#include <iostream>
#include <string>

using namespace std;

int main (void) {
	string strP, strS;
	int i, j;

	while (cin >> strP >> strS) {
		for (i = 0, j = 0; i < strP.size() && j < strS.size(); ++j)
			if (strP[i] == strS[j]) i ++;
		if (i == strP.size()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}
