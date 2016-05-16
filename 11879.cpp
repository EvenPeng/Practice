#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[]){
	char num[102];
	int sum;

	while(cin >> num && num[0] != '0'){
		sum = 0;
		for (int i = 0; num[i] != '\0'; ++i){
			sum = sum * 10 + (int)(num[i] - '0');
			sum %= 17;
		}

		if(sum > 0) cout << "0" << endl;
		else cout << "1" << endl;
	}
	
	return 0;
}