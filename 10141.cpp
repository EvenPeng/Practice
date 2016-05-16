#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[]){
	int product, member, met, met_tmp, index = 1;
	double price, price_tmp;
	string win, name;
	char tmp;
	bool flag;

	flag = false;
	
	while(1){
		cin >> product >> member;
		if(product < 1) break;

		if(flag) cout << endl;
		else flag = true;

		for (int i = 0; i < product; ++i){
			tmp = getchar();
			while(getchar() != '\n');
			//cin.ignore(81, '\n');
		}

		met = 0;

		for (int i = 0; i < member; ++i){
			cin >> name >> price_tmp >> met_tmp;
			for (int j = 0; j < met_tmp; ++j){
				tmp = getchar();
				while(getchar() != '\n');
				//cin.ignore(81, '\n');
			}

			if(met_tmp > met || (met_tmp == met && price_tmp < price)){
				win = name;
				price = price_tmp;
				met = met_tmp;
			}
		}

		cout << "RFP #" << index++ << endl;
		cout << win << endl;
	}

	return 0;
}