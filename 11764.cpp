#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
	int times, count, pre, curr, high, low, index = 1;

	cin >> times;

	for (int t = 0; t < times; ++t){
		high = 0;
		low = 0;
		cin >> count;
		cin >> pre;
		for (int i = 1; i < count; ++i){
			cin >> curr;
			if(curr > pre) high++;
			else if(curr < pre) low++;
			pre = curr;
		}
		cout << "Case " << index++ << ": " << high << " " << low << endl;
	}

	return 0;
}