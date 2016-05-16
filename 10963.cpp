#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char const *argv[]){
	int times, count, gap, north, south;
	bool flag;

	cin >> times;

	for (int i = 0; i < times; ++i){
		cin >> count;
		flag = true;
		cin >> north >> south;
		gap = abs(north - south);
		for (int j = 1	; j < count; ++j){
			cin >> north >> south;
			if(flag && abs(north - south) != gap)
				flag = false;
		}
		if(flag) cout << "yes" << endl;
		else cout << "no" << endl;
		if(i < times -1) cout << endl;	
	}

	return 0;
}