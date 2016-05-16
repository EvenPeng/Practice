#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[]){
	int count, tmp, sum = 0;
	string op;

	cin >> count;

	for (int i = 0; i < count; ++i){
		cin >> op;
		if(op.compare("donate") == 0){
			cin >> tmp;
			sum += tmp;
		}else
			cout << sum << endl;
	}

	return 0;
}