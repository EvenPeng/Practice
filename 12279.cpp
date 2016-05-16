#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
	int count, sum, tmp, index = 1;

	while(1){
		cin >> count;
		if(count < 1) break;
		sum = 0;
		for (int i = 0; i < count; ++i){
			cin >> tmp;
			if(tmp > 0) sum ++;
			else sum --;
		}
		cout << "Case " << index++ << ": " << sum << endl;
	}

	return 0;
}