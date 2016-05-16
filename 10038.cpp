#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[]){
	int len, pre, curr, flag;
	bool check[3000];

	while(cin >> len){
		for(int i = 1; i < len; ++i)
			check[i] = false;

		cin >> pre;
		for(int i = 1; i < len; ++i){
			cin >> curr;
			check[abs(pre - curr)] = true;
			pre = curr;
		}

		flag = true;
		for(int i = 1; i < len && flag; ++i)
			flag = flag && check[i];

		if(flag) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl; 
	}
	
	return 0;
}