#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
	int times, count, tmp, mile, juice;

	cin >> times;

	for (int i = 0; i < times; ++i){
		cin >> count;
		mile = 0;
		juice = 0;
		for (int j = 0; j < count; ++j){
			cin >> tmp;
			
			mile += tmp/30 *10 +10;
			juice += tmp/60 *15 +15;
		}
		cout << "Case " << i+1 << ": ";

		if(mile > juice) cout << "Juice " << juice << endl;
		else if(mile < juice) cout << "Mile " << mile << endl;
		else cout << "Mile Juice " << juice << endl;
	}

	return 0;
}