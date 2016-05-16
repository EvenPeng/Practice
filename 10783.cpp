#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[]){
	int times, a, b, index = 1;

	cin >> times;

	for (int tt = 0; tt < times; ++tt){
		cin >> a >> b;
		if(a % 2 == 0) a ++;
		if(b % 2 == 0) b --;
		cout << "Case " << index ++ << ": " << (a + b) * ((b - a) / 2 + 1) / 2 << endl;
	}
	
	return 0;
}