#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
	int times, x, y;

	cin >> times;

	for (int i = 0; i < times; ++i){
		cin >> x >> y;
		if(x > 3) x -= 2;
		if(y > 3) y -= 2;

		if(x % 3) x = x/3 + 1;
		else x = x/3;
		if(y % 3) y = y/3 + 1;
		else y = y/3;

		cout << x*y << endl;
	}

	return 0;
}