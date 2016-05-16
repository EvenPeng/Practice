#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
	int times, count, max, min, tmp;

	cin >> times;

	for (int i = 0; i < times; ++i){
		cin >> count >> tmp;
		max = tmp;
		min = tmp;
		for (int i = 1; i < count; ++i){
			cin >> tmp;
			if(tmp > max) max = tmp;
			else if(tmp < min) min  = tmp;
		}
		cout << 2*(max - min) << endl;
	}

	return 0;
}