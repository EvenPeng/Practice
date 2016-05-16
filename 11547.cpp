#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char const *argv[]){
	int count, in;

	cin >> count;

	for (int i = 0; i < count; ++i){
		cin >> in;
		in = (((in*567/9)+7492)*235/47)-498;
		in %= 100;
		in /= 10;
		cout << abs(in) << endl;
	}

	return 0;
}